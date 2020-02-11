/*
 * Send More Money.cpp
 */
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

typedef std::vector<int> vi;
typedef std::vector<char> vc;
typedef std::vector<vi> vii;

std::string a, b, c;

std::vector<char> input() {
	std::string eq;
	std::set<char> s;
	int plus;

	std::cin >> eq;

	for (int i = 0; i < (int) eq.length(); i++)
		if (eq[i] == '+')
			a = eq.substr(0, i), plus = i;
		else if (eq[i] == '=') {
			b = eq.substr(plus + 1, i - plus - 1);
			c = eq.substr(i + 1, eq.length() - 1);
		} else
			s.insert(eq[i]);

	return vc(s.begin(), s.end());
}

bool check_num(vi v, vc l) {
	int carry = 0, av, bv, cv, s;
	std::map<char, int> m;
	for (int i = 0; i < (int) v.size(); i++)
		m[l[i]] = v[i];

	for (int i = 0; i < (int) c.length(); i++) {
		av = i < (int) a.length() ? m[a[a.length() - i - 1]] : 0;
		bv = i < (int) b.length() ? m[b[b.length() - i - 1]] : 0;
		cv = m[c[c.length() - i - 1]];
		s = av + bv + carry;
		if ((s % 10) != cv)
			return false;
		carry = s / 10;
	}
	if (carry != 0)
		return false;

	for (int i = 0; i < (int) a.length(); i++)
		std::cout << (char) ('0' + m[a[i]]);
	std::cout << "+";
	for (int i = 0; i < (int) b.length(); i++)
		std::cout << (char) ('0' + m[b[i]]);
	std::cout << "=";
	for (int i = 0; i < (int) c.length(); i++)
		std::cout << (char) ('0' + m[c[i]]);

	return true;
}

bool found = false;
void generate_num(vi v, vc letters, std::set<char> f, std::set<int> u) {
	if (found)
		return;
	if (v.size() == letters.size()) {
		if (check_num(v, letters))
			found = true;

		return;
	}
	for (int i = f.count(letters[v.size()]) ? 1 : 0; i < 10; i++)
		if (!u.count(i)) {
			u.insert(i), v.push_back(i);
			generate_num(v, letters, f, u);
			v.pop_back(), u.erase(i);
		}
}

int main() {
	vc letters;
	std::set<char> forb;

	letters = input();

	if (letters.size() > 10 || c.length() < std::max(a.length(), b.length())) {
		printf("impossible");
		return 0;
	}
	forb.insert(a[0]), forb.insert(b[0]), forb.insert(c[0]);

	generate_num(vi(), letters, forb, std::set<int>());
	if (found)
		return 0;

	printf("impossible");
}

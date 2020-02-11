/*
 * XOR Equation.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int total = 0, a_q, b_q, c_index;
std::vector<int> c;
std::vector<std::string> num(3);
std::string a, b, f;

void add() {
	int f_a, f_b, f_n;
	std::string s_f;
	c_index = 0, a = num[0], b = num[1], f = num[2];

	for (int i = 0; i < (int) a.length(); i++)
		if (a[i] == '?')
			a[i] = c[c_index] + '0', c_index++;
	for (int i = 0; i < (int) b.length(); i++)
		if (b[i] == '?')
			b[i] = c[c_index] + '0', c_index++;

	f_a = stoi(a), f_b = stoi(b), f_n = (f_a ^ f_b);
	s_f = std::to_string(f_n);

	if ((a[0] == '0' && a != "0") || (b[0] == '0' && b != "0")
			|| s_f.length() != f.length())
		return;

	for (int i = 0; i < (int) s_f.length(); i++)
		if (s_f[i] != f[i] && f[i] != '?')
			return;
	total++;
}

void generate(int n) {
	if (n == 0) {
		add();
		return;
	}
	for (int i = 0; i < 10; i++)
		c.push_back(i), generate(n - 1), c.pop_back();
}

int main() {
	std::cin >> num[0] >> num[1] >> num[1] >> num[2] >> num[2];

	std::sort(num.begin(), num.end(), [](std::string a, std::string b) {
		return std::count(a.begin(), a.end(), '?') < std::count(b.begin(), b.end(), '?');});

	a_q = std::count(num[0].begin(), num[0].end(), '?');
	b_q = std::count(num[1].begin(), num[1].end(), '?');

	generate(a_q + b_q);

	std::cout << total;
}

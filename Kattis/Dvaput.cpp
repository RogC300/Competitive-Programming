/*
 * Dvaput.cpp
 */
#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

const int d = 26;
const int q = 200003;

typedef std::vector<int> vi;

std::unordered_map<int, vi> m;

bool has_repeat(int &length, std::string &s, int &n) {
	m.clear();
	long long int h = 1, p = 0;

	for (int i = 0; i < length - 1; i++)
		h = (h * d) % q;

	for (int i = 0; i < length; i++)
		p = (d * p + s[i]) % q;

	for (int i = 0; i <= n - length; i++) {
		if (m[p].size()) {
			bool cont = false;
			for (int j = 0; j < (int) m[p].size(); j++) {
				cont = true;
				for (int k = 0, l = i; k < length; k++, l++)
					if (s[m[p][j] + k] != s[l]) {
						cont = false;
						break;
					}
				if (cont)
					return true;
			}
//			std::cout << p << "\n";
//			return true;
		}
		m[p].push_back(i);
		if (i < n - length) {
			p = (d * (p - s[i] * h) + s[i + length]) % q;
			if (p < 0)
				p += q;
		}
	}
	return false;
}

int main() {
	int n;
	std::string s;
	std::cin >> n >> s;

	int low = 0, high = s.length(), m;
	while (low <= high) {
		m = (low + high) / 2;
		if (has_repeat(m, s, n))
			low = m + 1;
		else
			high = m - 1;
	}
//	m++;
	if (!has_repeat(m, s, n) && m != 0)
		m--;
	std::cout << m;
}


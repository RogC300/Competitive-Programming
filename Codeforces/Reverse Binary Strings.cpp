/*
 * Reverse Binary Strings.cpp
 */
#include <iostream>

void solve() {
	int n, one = 0, zero = 0;
	std::string s;

	std::cin >> n >> s;

	for (int i = 1; i < n; i++)
		if (s[i] == s[i - 1])
			s[i] == '1' ? one++ : zero++;

	std::cout << std::max(one, zero) << "\n";
}

int main() {
	int tc = 1;
	std::cin >> tc;
	while (tc--)
		solve();
}

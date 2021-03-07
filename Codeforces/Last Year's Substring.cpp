/*
 * Last Year's Substring.cpp
 */
#include <iostream>
#include <vector>

bool solve() {
	int n;
	std::string s;
	std::cin >> n >> s;

	if (s[0] == '2' && s.substr(n - 3, 3) == "020")
		return true;
	if (s.substr(0, 3) == "202" && s[n - 1] == '0')
		return true;
	if (s.substr(0, 2) == "20" && s.substr(n - 2, 2) == "20")
		return true;
	if (s.substr(0, 4) == "2020" || s.substr(n - 4, 4) == "2020")
		return true;
	return false;
}

int main() {
	int tc;
	std::cin >> tc;

	while (tc--)
		std::cout << (solve() ? "YES" : "NO") << "\n";
}

/*
 * Longest Palindrome.cpp
 */
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

bool is_pal(std::string s) {
	for (int i = 0; i < (int) s.length(); i++)
		if (s[i] != s[s.length() - i - 1])
			return false;
	return true;
}

int main() {
	std::map<std::string, int> m;
	int n, length;
	std::string s, reverse, max_pal = "", ans = "";
	std::vector<std::pair<std::string, std::string>> pairs;

	std::cin >> n >> length;
	for (int i = 0; i < n; i++) {
		std::cin >> s, reverse = s, std::reverse(reverse.begin(), reverse.end());
		if (m[reverse] > 0)
			pairs.push_back( { s, reverse }), m[reverse]--;
		else
			m[s]++;
	}

	for (auto i : m)
		if (i.second == 1 && is_pal(i.first))
			if (i.first.length() > max_pal.length())
				max_pal = i.first;

	for (int i = 0; i < (int) pairs.size(); i++)
		ans += pairs[i].first;
	ans += max_pal;
	for (int i = pairs.size() - 1; i >= 0; i--)
		ans += pairs[i].second;

	std::cout << ans.length() << "\n" << ans;
}

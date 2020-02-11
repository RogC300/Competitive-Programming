/*
 * Touchscreen Keyboard.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

int d(std::pair<int, int>& p1, std::pair<int, int>& p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

bool cmp(std::pair<std::string, int>& p1, std::pair<std::string, int>& p2) {
	if (p1 == p2)
		return false;
	if (p1.second == p2.second)
		return p1.first < p2.first;
	return p1.second < p2.second;
}

int main() {
	std::vector<std::string> v;
	v.push_back("qwertyuiop");
	v.push_back("asdfghjkl");
	v.push_back("zxcvbnm");

	std::map<char, std::pair<int, int>> pos;
	for (int i = 0; i < (int) v.size(); i++)
		for (int j = 0; j < (int) v[i].size(); j++)
			pos[v[i][j]] = {i,j};
	int cases;
	std::cin >> cases;
	while (cases--) {
		std::string s;
		int n;
		std::cin >> s >> n;
		std::vector<std::pair<std::string, int>> m;
		for (int i = 0; i < n; i++) {
			std::string t;
			std::cin >> t;

			int diff = 0;
			for (int j = 0; j < (int) t.size(); j++) {
				std::pair<int, int> p1 = pos[s[j]];
				std::pair<int, int> p2 = pos[t[j]];
				diff += d(p1, p2);
			}
			m.push_back( { t, diff });
		}
		std::sort(m.begin(), m.end(), cmp);
		for (auto i : m)
			std::cout << i.first << " " << i.second << std::endl;
	}
}

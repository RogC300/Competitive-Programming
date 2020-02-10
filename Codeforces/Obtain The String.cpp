/*
 * Obtain The String.cpp
 */
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

bool possible(std::string s, std::string end) {
	std::set<char> set;

	for (int i = 0; i < (int) s.length(); i++)
		set.insert(s[i]);

	for (int i = 0; i < (int) end.length(); i++)
		if (!set.count(end[i]))
			return false;
	return true;
}

int main() {
	std::string s, e;
	std::map<char, std::vector<int>> m;
	int count, tc;

	std::cin >> tc;

	while (tc--) {
		std::cin >> s >> e, count = 1, m.clear();

		for (int i = 0; i < (int) s.length(); i++)
			m[s[i]].push_back(i);

		if (!possible(s, e)) {
			std::cout << -1 << "\n";
			continue;
		}
//		for (auto i : m) {
//			std::cout << i.first << ": ";
//			for (auto j : i.second)
//				std::cout << j << " ";
//			std::cout << "\n";
//		}
		for (int i = 0, cur = -1, place; i < (int) e.length(); i++) {
			place = std::upper_bound(m[e[i]].begin(), m[e[i]].end(), cur)
					- m[e[i]].begin();
			if (place == (int) m[e[i]].size())
				count++, cur = m[e[i]][0];
			else
				cur = m[e[i]][place];
		}

		std::cout << count << "\n";
	}
}

/*
 * Air Conditioner.cpp
 */
#include <iostream>
#include <map>
#include <vector>

int main() {
	int n, temp, temp_diff, prev_time, lower, upper, l, h, tc;
	std::map<int, std::vector<std::pair<int, int>>> m;
	std::map<int, std::pair<int, int>> people;
	bool possible = true;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n >> temp;
		m.clear(), people.clear(), prev_time = 0;
		lower = upper = temp, possible = true;

		for (int i = 0, t; i < n; i++)
			std::cin >> t >> l >> h, m[t].push_back( { l, h });

		for (auto i : m) {
			l = -1e9, h = 1e9;
			for (auto j : i.second)
				l = std::max(l, j.first), h = std::min(h, j.second);
			if (l > h) {
				possible = false;
				break;
			}
			people[i.first] = { l, h };
		}
		for (auto i = people.begin(); i != people.end(); i++) {
			temp_diff = i->first - prev_time, prev_time = i->first;
			lower = lower - temp_diff, upper = upper + temp_diff;

			l = i->second.first, h = i->second.second;

			if (upper < l || lower > h) {
				possible = false;
				break;
			}
			lower = std::max(lower, l), upper = std::min(h, upper);
		}
		std::cout << (possible ? "YES" : "NO") << "\n";
	}
}

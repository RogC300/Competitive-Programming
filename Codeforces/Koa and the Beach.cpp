/*
 * Koa and the Beach.cpp
 */
#include <iostream>
#include <vector>

std::vector<int> ocean;
int change, level;

bool check_safe(int beg, int end) {
	int tides = level - ocean[beg + 1];
	bool tide_up = false;
	for (int i = beg + 1; i < end; i++) {
		if (ocean[i] > level)
			return false;
		if (ocean[i] + tides > level) {
			if (tide_up)
				return false;
			tides = level - ocean[i];
		}
		if (tides == change)
			tide_up = false;
		if (tides == 0)
			tide_up = true;
		tides += (tide_up ? 1 : -1);
	}
	return true;
}

int main() {
	int n, tc;
	std::vector<int> safe;
	bool possible;

	std::cin >> tc;
	while (tc--) {
		std::cin >> n >> change >> level;
		safe.clear(), ocean.clear(), possible = true;

		ocean.push_back(-1e9);
		for (int i = 0, in; i < n; i++)
			std::cin >> in, ocean.push_back(in);
		ocean.push_back(-1e9), n += 2;
		for (int i = 0; i < n; i++)
			if (ocean[i] + change <= level)
				safe.push_back(i);

		for (int i = 0; i < (int) safe.size() - 1 && possible; i++)
			if (!check_safe(safe[i], safe[i + 1]))
				possible = false;

		std::cout << (possible ? "Yes" : "No") << "\n";
	}
}

/*
 * 12192 - Grapevine.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int h = -1, w = -1;
	std::vector<std::vector<int>> map;
	while (std::cin >> h >> w && h != 0 && w != 0) {
		map.resize(h), map.clear();
		for (int i = 0; i < h; i++)
			for (int j = 0, height; j < w; j++)
				std::cin >> height, map[i].push_back(height);
		int num_of_limits;
		std::cin >> num_of_limits;
		while (num_of_limits--) {
			int lower_limit, upper_limit, best_size = 0;
			std::cin >> lower_limit >> upper_limit;
			bool found = false;
			for (int i = 0; i < h; i++) {
				auto index = std::lower_bound(map[i].begin(), map[i].end(),
						lower_limit);
				if (index == map[i].end() || *index > upper_limit)
					continue;
				if (!found)
					best_size = 1, found = true;

				for (int j = 0;
						j < std::min(h - i, w - (int)(index - map[i].begin()));
						j++) {
					if (map[i + j][(index - map[i].begin()) + j]
							> upper_limit) {
						best_size = std::max(best_size, j);
						break;
					}
					if (j == std::min(h - i,
									w - (int) (index - map[i].begin())) - 1
							&& map[i + j][(index - map[i].begin()) + j]
									<= upper_limit) {
						best_size = std::max(best_size, j + 1);
						break;
					}
				}
			}
			std::cout << best_size << std::endl;
		}
		std::cout << "-\n";
	}
}
/*
 4 4
 1 7 9 11
 5 8 10 12
 7 10 15 17
 11 19 30 41
 4
 6 20
 7 9
 10 10
 13 14
 0 0
 */

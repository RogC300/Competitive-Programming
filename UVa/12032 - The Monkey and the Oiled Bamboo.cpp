/*
 * 12032 - The Monkey and the Oiled Bamboo.cpp
 */
#include <iostream>
#include <vector>

std::vector<int> rung_heights;

bool try_strength(int strength) {
	int current = 0;
	for (int i = 0; i < (int) rung_heights.size(); i++) {
		if (rung_heights[i] - current > strength)
			return false;
		if (rung_heights[i] - current == strength)
			strength--;
		current = rung_heights[i];
	}
	return true;
}

int main() {
	int cases, case_number = 1;
	std::cin >> cases;
	while (cases--) {
		int num_of_rungs;
		std::cin >> num_of_rungs;
		rung_heights.clear();
		for (int i = 0, height; i < num_of_rungs; i++)
			std::cin >> height, rung_heights.push_back(height);

		int low = 1, hi = rung_heights.back(), mid;
		while (low <= hi) {
			mid = (low + hi) / 2;
			if (try_strength(mid))
				hi = mid - 1;
			else
				low = mid + 1;
		}
		printf("Case %d: %d\n", case_number++, low);
	}
}

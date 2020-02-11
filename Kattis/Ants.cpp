/*
 * Ants.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;

	while (n--) {
		int length, num_ants, min = 0, max = 0;
		std::vector<int> pos;

		std::cin >> length >> num_ants;

		for (int i = 0, p; i < num_ants; i++) {
			std::cin >> p;
			pos.push_back(p);
			min = std::max(std::min(p, length - p), min);
			max = std::max(std::max(p, length - p), max);
		}

		std::cout << min << " " << max << "\n";
	}
}

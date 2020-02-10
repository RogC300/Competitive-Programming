/*
 * Verse For Santa.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n_verses, tc;
	long long int time, total_time;
	std::vector<long long int> verses;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n_verses >> time;
		total_time = 0;
		verses.resize(n_verses);

		for (int i = 0; i < n_verses; i++)
			std::cin >> verses[i], total_time += verses[i];

		if (total_time > time) {
			int max = 0, sum = 0, loc;
			for (int i = 0; i < n_verses; i++) {
				if (verses[i] > max)
					max = verses[i], loc = i;
				sum += verses[i];
				if (sum > time) {
					std::cout << loc + 1 << "\n";
					break;
				}
			}
		} else
			std::cout << 0 << "\n";
	}
}

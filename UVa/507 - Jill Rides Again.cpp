/*
 * 507 - Jill Rides Again.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int num_of_routes;
	std::cin >> num_of_routes;
	int num_stops, happy, start, max;
	std::vector<std::pair<int, int>> pairs;
	for (int k = 1; k <= num_of_routes; k++) {
		std::cin >> num_stops;
		happy = 0, start = 1, max = 0;
		for (int i = 1, path; i < num_stops; i++) {
			std::cin >> path;
			happy += path;
			if (happy > max
					|| (happy == max
							&& (start == pairs[pairs.size() - 1].first
									|| i - start
											> pairs[pairs.size() - 1].second
													- pairs[pairs.size() - 1].first)))
				max = happy, pairs.push_back(std::make_pair(start, i));
			if (happy < 0)
				happy = 0, start = i + 1;
		}
		if (max == 0)
			printf("Route %d has no nice parts\n", k);
		else
			printf("The nicest part of route %d is between stops %d and %d\n",
					k, pairs[pairs.size() - 1].first,
					pairs[pairs.size() - 1].second + 1);
	}
}

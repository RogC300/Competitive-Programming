/*
 * 11413 - Fill the Containers.cpp
 */
#include <iostream>
#include <vector>

std::vector<int> vessels;
int num_of_vessels, num_of_containers;

bool try_capacity(int max_capacity) {
	int used_containers = 1, current_capacity = 0;
	for (int i = 0; i < num_of_vessels; i++) {
		if (vessels[i] > max_capacity)
			return false;
		if (current_capacity + vessels[i] > max_capacity)
			current_capacity = 0, used_containers++;
		if (used_containers > num_of_containers)
			return false;
		current_capacity += vessels[i];
	}
	return true;
}

int main() {
	while (std::cin >> num_of_vessels >> num_of_containers) {
		vessels.clear();
		int best_size = -1, lo = 1, hi = 0, mid;
		for (int i = 0, milk; i < num_of_vessels; i++)
			std::cin >> milk, vessels.push_back(milk), hi += milk;

		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (try_capacity(mid))
				hi = mid - 1, best_size = mid;
			else
				lo = mid + 1;
		}
		std::cout << best_size << "\n";
	}
}

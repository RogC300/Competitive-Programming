/*
 * Captain Flint and a Long Voyage.cpp
 */
#include <iostream>
#include <cmath>

int main() {
	int n, num_eight, tc;

	std::cin >> tc;
	while (tc--) {
		std::cin >> n;
		num_eight = ceil((double) n / 4);

		for (int i = 0; i < n - num_eight; i++)
			std::cout << "9";
		while (num_eight--)
			std::cout << "8";
		std::cout << "\n";
	}
}

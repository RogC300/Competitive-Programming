/*
 * 11100 - The Trip, 2007.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int pieces_of_luggage, max_sizes;
	bool first = false;
	std::vector<int> pieces, num_of_sizes;
	while (std::cin >> pieces_of_luggage && pieces_of_luggage != 0) {
		num_of_sizes.resize(10005), std::fill(num_of_sizes.begin(),
				num_of_sizes.end(), 0), pieces.clear(), max_sizes = 0;
		for (int i = 0, size; i < pieces_of_luggage; i++)
			std::cin >> size, pieces.push_back(size), num_of_sizes[size]++, max_sizes =
					std::max(max_sizes, num_of_sizes[size]);

		std::sort(pieces.begin(), pieces.end());
		std::cout << (first == false ? "" : "\n") << max_sizes << "\n";
		first = true;
		for (int i = 0; i < max_sizes; i++)
			for (int j = i; j < pieces_of_luggage; j += max_sizes)
				std::cout << pieces[j]
						<< (j + max_sizes >= pieces_of_luggage ? "\n" : " ");
	}
}


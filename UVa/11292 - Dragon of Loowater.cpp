/*
 * 11292 - Dragon of Loowater.cpp
 */
#include <iostream>
#include <algorithm>

int main() {
	int num_of_heads, num_of_knights;
	while (std::cin >> num_of_heads >> num_of_knights && num_of_heads != 0
			&& num_of_knights != 0) {
		int heads[num_of_heads], knights[num_of_knights], coins = 0;
		for (int i = 0; i < num_of_heads; i++)
			std::cin >> heads[i];
		for (int i = 0; i < num_of_knights; i++)
			std::cin >> knights[i];
		bool safe = true;
		std::sort(heads, heads + num_of_heads), std::sort(knights,
				knights + num_of_knights);
		for (int h = 0, k = 0; h < num_of_heads && safe; h++) {
			while (k < num_of_knights && knights[k] < heads[h])
				k++;
			if (k == num_of_knights)
				safe = false;
			else
				coins += knights[k++];
		}
		std::cout
				<< (safe == true ? std::to_string(coins) : "Loowater is doomed!")
				<< "\n";
	}
}


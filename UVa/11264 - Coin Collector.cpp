/*
 * 11264 - Coin Collector.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int cases;
	std::cin >> cases;
	while (cases--) {
		int num_of_coins, unique = 2;
		std::cin >> num_of_coins;
		std::vector<int> coins;
		for (int i = 0, value; i < num_of_coins; i++)
			std::cin >> value, coins.push_back(value);

		for (int i = 1, sum = 1; i < num_of_coins - 1; i++)
			if (sum + coins[i] < coins[i + 1])
				sum += coins[i], unique++;

		printf("%d\n", unique);
	}
}

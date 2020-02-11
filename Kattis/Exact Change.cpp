/*
 * Exact Change.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int cases;

	int target, num_coins;
	std::vector<int> coins, dp;

	std::cin >> cases;

	while (cases--) {
		std::cin >> target >> num_coins;
		dp.assign(30000, 1e9), coins.resize(num_coins), dp[0] = 0;

		for (int i = 0; i < num_coins; i++)
			std::cin >> coins[i];

		std::sort(coins.begin(), coins.end());

		for (auto i : coins)
			for (int j = 30000 - i - 1; j >= 0; j--)
				if (dp[j] < 1e9)
					dp[j + i] = std::min(dp[j + i], dp[j] + 1);

		for (int i = target;; i++)
			if (dp[i] < 1e9) {
				std::cout << i << " " << dp[i] << "\n";
				break;
			}
	}
}

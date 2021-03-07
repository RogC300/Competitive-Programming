/*
 * 674 - Coin Change.cpp
 */
#include <iostream>
#include <string.h>

int coins[5] = { 1, 5, 10, 25, 50 };
unsigned long long int dp[30001];

int main() {
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < 5; i++)
		for (int j = coins[i]; j <= 30000; j++)
			dp[j] += dp[j - coins[i]];
	int amount;
	while (std::cin >> amount)
		std::cout << dp[amount] << "\n";
}

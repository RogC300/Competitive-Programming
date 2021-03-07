/*
 * 147 - Dollars.cpp
 */
#include <iostream>
#include <iomanip>
#include <string.h>
#include <math.h>

int coins[11] = { 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5 };

long long int coin_change(int sum) {
//	std::cout << sum << std::endl;
	long long int dp[sum + 1];
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	for (int i = 0; i < 11; i++)
		for (int j = 1; j <= sum; j++)
			dp[j] += (j - coins[i] >= 0 ? dp[j - coins[i]] : 0);
	return dp[sum];
}

int main() {
	double sum;
	while (std::cin >> sum && sum != 0)
		std::cout << std::setw(6) << std::fixed << std::setprecision(2) << sum
				<< std::setw(17) << coin_change(round(sum * 100)) << "\n";
}

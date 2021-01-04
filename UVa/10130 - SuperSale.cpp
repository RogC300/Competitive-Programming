/*
 * 10130 - SuperSale.cpp
 */
#include <iostream>
#include <vector>

std::vector<int> p, w;

int knapsack(int weight, int n) {
	int dp[n + 1][weight + 1];

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= weight; j++) {
			if (j == 0 || i == 0)
				dp[i][j] = 0;
			else if (w[i - 1] <= j)
				dp[i][j] = std::max(dp[i - 1][j],
						dp[i - 1][j - w[i - 1]] + p[i - 1]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	return dp[n][weight];
}

int main() {
	int tc;
	std::cin >> tc;

	while (tc--) {
		int n, num_people, person;
		p.clear(), w.clear();
		std::cin >> n;
		for (int i = 0, price, weight; i < n; i++)
			std::cin >> price >> weight, p.push_back(price), w.push_back(weight);

		std::cin >> num_people;
		int sum = 0;
		while (num_people--)
			std::cin >> person, sum += knapsack(person, n);
		printf("%d\n", sum);

	}
}

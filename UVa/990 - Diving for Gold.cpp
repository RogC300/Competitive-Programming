/*
 * 990 - Diving for Gold.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int multiplier;

void knapSack(int weight_capacity, std::vector<int> weights,
		std::vector<int> values, int num_items) {
	int dp[num_items + 1][weight_capacity + 1];
	for (int i = 0; i <= num_items; i++)
		for (int j = 0; j <= weight_capacity; j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (weights[i - 1] <= j)
				dp[i][j] = std::max(
						values[i - 1] + dp[i - 1][j - weights[i - 1]],
						dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}

	int ans[35], k = 0, sum = 0;
	while (num_items > 0) {
		if (dp[num_items][weight_capacity]
				!= dp[num_items - 1][weight_capacity]) {
			ans[k++] = num_items - 1;
			weight_capacity -= weights[num_items - 1];
			sum += values[num_items - 1];
		}
		num_items--;
	}
	printf("%d\n%d\n", sum, k);
	for (int i = k - 1; i >= 0; i--)
		printf("%d %d\n", weights[ans[i]] / 3 / multiplier, values[ans[i]]);
}

int main() {
	int weight_capacity, num_items, end = false;
	while (std::cin >> weight_capacity >> multiplier) {
		std::cin >> num_items;
		end == false ? end = true : puts("");
		std::vector<int> values(num_items), weights(num_items);

		for (int i = 0; i < num_items; i++)
			std::cin >> weights[i] >> values[i], weights[i] *= multiplier * 3;

		knapSack(weight_capacity, weights, values, num_items);
	}
}

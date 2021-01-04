/*
 * 10306 - e-Coins.cpp
 */
/* MEMOIZED VERSION
#include <iostream>
#include <vector>
#include <string.h>

std::vector<std::pair<int, int>> triplet_pairs, e_coins;
int minimum_coins = 1e9, memo[300][300][300];

void find_triplet_pairs(int c) {
	triplet_pairs.clear();
	int c_squared = c * c;
	for (int i = 0; i <= c; i++)
		for (int j = i; j <= c; j++) {
			if (i * i + j * j == c_squared)
				triplet_pairs.push_back(std::make_pair(i, j));
			else if (i * i + j * j > c_squared)
				break;
		}
}

void recurse(std::pair<int, int> pair, int count, int a, int b) {
	if (a > pair.first || b > pair.second || memo[a][b][count] == 1)
		return;
	memo[a][b][count] = 1;
	if (a == pair.first && b == pair.second)
		minimum_coins = std::min(minimum_coins, count);

	for (int i = 0; i < (int) e_coins.size(); i++)
		recurse(pair, count + 1, a + e_coins[i].first, b + e_coins[i].second);
}

int main() {
	int tc;
	std::cin >> tc;
	while (tc--) {
		e_coins.clear(), minimum_coins = 1e9;
		int num_e_coins, e_modulus;
		std::cin >> num_e_coins >> e_modulus;
		find_triplet_pairs(e_modulus);
		for (int i = 0, conventional_value, info_tech_value; i < num_e_coins;
				i++)
			std::cin >> conventional_value >> info_tech_value, e_coins.push_back(
					std::make_pair(conventional_value, info_tech_value));

		for (int i = 0; i < (int) triplet_pairs.size(); i++) {
			std::pair<int, int> temp;
			memset(memo, 0, sizeof(memo));
			temp.first = triplet_pairs[i].second, temp.second =
					triplet_pairs[i].first;
			recurse(triplet_pairs[i], 0, 0, 0);
			memset(memo, 0, sizeof(memo));
			recurse(temp, 0, 0, 0);
		}

		if (minimum_coins != 1e9)
			std::cout << minimum_coins << "\n";
		else
			puts("not possible");
	}
}
*/
// TABULATED VERSION
#include <iostream>
#include <string.h>

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int m, s;
		scanf("%d%d", &m, &s);
		int dp[301][301];
		for (int j = 0; j <= s; j++)
			for (int k = 0; k <= s; k++)
				dp[j][k] = 1e7;
		dp[0][0] = 0;
		while (m--) {
			int x, y;
			scanf("%d%d", &x, &y);
			for (int j = x; j <= s; j++)
				for (int k = y; k <= s; k++)
					dp[j][k] = std::min(dp[j][k], dp[j - x][k - y] + 1);
		}
		int ans = 1e7;
		for (int j = 0; j <= s; j++)
			for (int k = 0; k <= s; k++)
				if (j * j + k * k == s * s)
					ans = std::min(ans, dp[j][k]);

		if (ans >= 1e7)
			puts("not possible");
		else
			printf("%d\n", ans);
	}
}

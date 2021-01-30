/*
 * Combining Riceballs.cpp
 */
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> rice, pre_sum;

int sum(int l, int r) {
	return pre_sum[r] - pre_sum[l] + rice[l];
}

int solve() {
	int max_s = 0;
	vector<vector<bool>> dp(n, vector<bool>(n, false));

	for (int length = 1; length <= n; length++)
		for (int l = 0, r; l + length <= n; l++) {
			r = l + length - 1;
			if (l == r)
				dp[l][r] = true;

			for (int i = l; i < r; i++)
				if (dp[l][i] && dp[i + 1][r] && sum(l, i) == sum(i + 1, r))
					dp[l][r] = true;

			for (int mid_length = 1; mid_length + 2 <= length; mid_length++)
				for (int i = l + 1, j; i <= r - mid_length; i++) {
					j = i + mid_length - 1;
					if (dp[l][i - 1] && dp[i][j] && dp[j + 1][r] && sum(l, i - 1) == sum(j + 1, r))
						dp[l][r] = true;
				}
			if (dp[l][r])
				max_s = std::max(max_s, sum(l, r));
		}

	return max_s;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> n, rice.resize(n);

	for (int i = 0; i < n; i++)
		std::cin >> rice[i];
	pre_sum = rice;
	for (int i = 1; i < n; i++)
		pre_sum[i] += pre_sum[i - 1];

	std::cout << solve();
}

/*
 * Chef Monocarp.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
	int n;
	std::vector<int> v;
	std::vector<std::vector<int>> dp(205, std::vector<int>(405, 1e9));
	std::cin >> n, v.resize(n);

	for (int i = 0; i < n; i++)
		std::cin >> v[i], v[i]--;

	std::sort(v.begin(), v.end()), dp[0][0] = 0;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j < n * 2; j++)
			if (dp[i][j] < 1e9) {
				dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j] + abs(v[i] - j));
				dp[i][j + 1] = std::min(dp[i][j], dp[i][j + 1]);
			}
	printf("%d\n", dp[n][2 * n - 1]);
}

int main() {
	int tc = 1;
	std::cin >> tc;
	while (tc--)
		solve();
}

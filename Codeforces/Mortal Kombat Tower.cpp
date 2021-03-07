/*
 * Mortal Kombat Tower.cpp
 */
#include <iostream>
#include <vector>

void solve() {
	int n;
	std::vector<int> v;
	std::vector<std::vector<int>> dp;
	std::cin >> n, v.resize(n);
	dp.assign(n + 1, std::vector<int>(2, 1e9));
	dp[0][1] = 0;
	for (int i = 0; i < n; i++)
		std::cin >> v[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 1, hard; k <= std::min(n - i, 2); k++) {
				hard = v[i] + (k > 1 ? v[i + 1] : 0);
				dp[i + k][!j] = std::min(dp[i + k][!j], dp[i][j] + hard * j);
			}
	std::cout << std::min(dp[n][0], dp[n][1]) << "\n";
}

int main() {
	int tc = 1;
	std::cin >> tc;

	while (tc--)
		solve();
}

/*
 * Consecutive Subsequence.cpp
 */
#include <iostream>
#include <vector>
#include <map>

void solve(std::vector<int> v, int n) {
	std::map<int, int> dp;
	int max, ans = 0;

	for (int i = 0; i < n; i++)
		dp[v[i]] = std::max(dp[v[i]], dp[v[i] - 1] + 1);
	for (auto i : dp)
		if (i.second > ans)
			ans = i.second, max = i.first;

	std::cout << ans << "\n";

	std::vector<int> out;
	for (int i = n - 1; i >= 0; i--)
		if (v[i] == max)
			out.push_back(i + 1), max--;

	for (int i = out.size() - 1; i >= 0; i--)
		std::cout << out[i] << " ";
}

int main() {
	int n;
	std::cin >> n;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	solve(v, n);
}

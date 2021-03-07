/*
 * Maximum White Subtree.cpp
 */
#include <iostream>
#include <vector>

typedef std::vector<int> vi;

std::vector<vi> adj;
vi values, dp, ans;

void find_start(int v, int from = -1) {
	dp[v] = values[v];
	for (auto u : adj[v])
		if (u != from)
			find_start(u, v), dp[v] += std::max(0, dp[u]);
}

void find_rest(int v, int from = -1) {
	ans[v] = dp[v];

	for (auto u : adj[v])
		if (u != from) {
			dp[v] -= std::max(0, dp[u]), dp[u] += std::max(0, dp[v]);
			find_rest(u, v);
			dp[u] -= std::max(0, dp[v]), dp[v] += std::max(0, dp[u]);
		}
}

int main() {
	int n;
	std::cin >> n, dp = values = ans = vi(n), adj.resize(n);
	for (int i = 0; i < n; i++)
		std::cin >> values[i], values[i] = (values[i] ? 1 : -1);

	for (int i = 0, v, u; i < n - 1; i++) {
		std::cin >> v >> u, v--, u--;
		adj[v].push_back(u), adj[u].push_back(v);
	}
	find_start(0), find_rest(0);
	for (auto i : ans)
		std::cout << i << " ";
}

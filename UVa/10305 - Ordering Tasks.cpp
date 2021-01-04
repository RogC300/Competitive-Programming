/*
 * 10305 - Ordering Tasks.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int n;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;
std::vector<int> ans;

void dfs(int v) {
	visited[v] = true;
	for (int u = 0; u < (int) adj[v].size(); u++)
		if (!visited[adj[v][u]])
			dfs(adj[v][u]);
	ans.push_back(v);
}

void topological_sort() {
	visited.assign(n, false);
	ans.clear();
	for (int i = 0; i < n; ++i)
		if (!visited[i])
			dfs(i);
	std::reverse(ans.begin(), ans.end());
}

void print_v(std::vector<int> v) {
	for (int i = 0; i < (int) v.size(); i++)
		std::cout << v[i] + 1 << (i == (int) v.size() - 1 ? "\n" : " ");
}

int main() {
	int num_connections;
	while (std::cin >> n >> num_connections, n != 0 || num_connections != 0) {
		adj.clear(), adj.resize(n), ans.clear();
		for (int i = 0, a, b; i < num_connections; i++)
			std::cin >> a >> b, adj[a - 1].push_back(b - 1);

		if (num_connections == 0) {
			for (int i = 1; i <= n; i++)
				std::cout << i << (i == n ? "\n" : " ");
			continue;
		}
		topological_sort();
		print_v(ans);
	}
}

/*
 * Tree Queries.cpp
 */
#include <iostream>
#include <vector>

int tour = 0;
std::vector<std::vector<int>> adj;
std::vector<int> parent, depth, in, out;

void dfs(int v, int par = -1, int dep = 0) {
	in[v] = tour++, parent[v] = par, depth[v] = dep;
	for (auto u : adj[v])
		if (u != par)
			dfs(u, v, dep + 1);
	out[v] = tour++;
}

bool is_ancestor(int ancestor, int v) {
	return in[ancestor] <= in[v] && out[v] <= out[ancestor];
}

int main() {
	int n, m, num_q, lowest_v;
	std::vector<int> queries;
	bool possible;

	std::cin >> n >> m;
	adj.resize(n), parent = depth = in = out = std::vector<int>(n);

	for (int i = 0, v, u; i < n - 1; i++) {
		std::cin >> v >> u;
		adj[v - 1].push_back(u - 1);
		adj[u - 1].push_back(v - 1);
	}
	dfs(0);

	while (m--) {
		std::cin >> num_q, queries.resize(num_q), lowest_v = 0, possible = true;
		for (int i = 0; i < num_q; i++) {
			std::cin >> queries[i], queries[i]--;
			if (depth[queries[i]] > depth[lowest_v])
				lowest_v = queries[i];
		}
		for (auto &u : queries)
			if (u != lowest_v && parent[u] != -1)
				u = parent[u];
		for (auto u : queries)
			possible &= is_ancestor(u, lowest_v);
		std::cout << (possible ? "YES" : "NO") << "\n";
	}
}

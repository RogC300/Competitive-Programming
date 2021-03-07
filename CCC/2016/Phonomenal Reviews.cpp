/*
 * Phonomenal Reviews.cpp
 */
#include <bits/stdc++.h>

std::vector<std::set<int>> adj;
std::unordered_set<int> waste;
std::set<int> pho;
int n, m;

void prune(int v) {
	std::queue<int> q;
	q.push(v);

	while (!q.empty()) {
		v = q.front(), q.pop();

		if (adj[v].size() > 1 || pho.count(v))
			break;

		waste.insert(v);
		for (auto u : adj[v])
			if (waste.count(u) == 0)
				q.push(u), adj[u].erase(v);
	}
}

std::pair<int, int> furthest(int v) {
	std::queue<int> q;
	int mx_d = 0, f = 0;
	std::vector<int> d(n, -1e9);

	q.push(v), d[v] = 0;

	while (!q.empty()) {
		v = q.front(), q.pop();

		for (auto u : adj[v])
			if (d[u] == -1e9 && waste.count(u) == 0)
				q.push(u), d[u] = d[v] + 1;
	}
	for (int i = 0; i < n; i++)
		mx_d = std::max(mx_d, d[i]);
	for (int i = 0; i < n; i++)
		if (d[i] == mx_d)
			f = i;
	return {f, mx_d};
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> n >> m;
	adj.resize(n);

	for (int i = 0, p; i < m; i++)
		std::cin >> p, pho.insert(p);

	for (int i = 0, v, u; i < n - 1; i++) {
		std::cin >> v >> u;
		adj[v].insert(u), adj[u].insert(v);
	}
	for (int i = 0; i < n; i++)
		if (adj[i].size() == 1)
			prune(i);

	std::cout
			<< 2 * (n - 1 - waste.size())
					- furthest(furthest(*pho.begin()).first).second;
}

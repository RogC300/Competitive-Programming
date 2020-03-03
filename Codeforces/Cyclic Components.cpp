/*
 * Cyclic Components.cpp
 */
#include <iostream>
#include <vector>
#include <queue>

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

vvi adj;
vi seen;

bool bfs(int s) {
	bool cycle = true;
	int t;
	std::queue<int> st;

	st.push(s);
	seen[s] = true;

	while (!st.empty()) {
		t = st.front(), st.pop();
		if (adj[t].size() != 2)
			cycle = false;

		for (auto i : adj[t])
			if (!seen[i])
				seen[i] = true, st.push(i);
	}
	return cycle;
}

int main() {
	int n, m, count = 0;
	std::cin >> n >> m, adj.resize(n), seen.assign(n, false);

	for (int i = 0, u, v; i < m; i++) {
		std::cin >> u >> v;
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}

	for (int i = 0; i < n; i++)
		if (!seen[i])
			if (bfs(i))
				count++;
	std::cout << count;
}

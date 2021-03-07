/*
 * Who is Taller.cpp
 */
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

bool bfs(int v, int u) {
	queue<int> q;
	int cur;
	vector<bool> seen(adj.size(), false);

	q.push(v), seen[v] = true;

	while (!q.empty()) {
		cur = q.front(), q.pop();
		if (cur == u)
			return true;
		for (auto e : adj[cur])
			if (!seen[e])
				q.push(e), seen[e] = true;
	}
	return false;
}

int main() {
	int n, m, p, q;
	std::cin >> n >> m, adj.resize(n);

	for (int i = 0, a, b; i < m; i++)
		std::cin >> a >> b, adj[a - 1].push_back(b - 1);
	std::cin >> p >> q, p--, q--;
	cout << (bfs(p, q) ? "yes" : (bfs(q, p) ? "no" : "unknown"));
}

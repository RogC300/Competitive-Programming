/*
 * Convex Hull.cpp
 */
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
struct edge {
	int u, t, h;
	edge(int u, int t, int h) {
		this->u = u, this->t = t, this->h = h;
	}
};

vector<vector<edge>> adj;
int n;

void dijkstra(int k, int a, int b) {
	priority_queue<pii, vector<pii>, greater<pii>> q;
	vector<vector<int>> d(n, vector<int>(k, 1e9));
	vector<bool> in_q(n, false);
	int v, min_p = 1e9;

	d[a][0] = 0, q.push( { 0, a }), in_q[a] = true;

	while (!q.empty()) {
		v = q.top().second, q.pop(), in_q[v] = false;

		for (auto e : adj[v])
			for (int i = 0; i + e.h < k; i++)
				if (d[v][i] + e.t < d[e.u][i + e.h]) {
					d[e.u][i + e.h] = d[v][i] + e.t;
					if (!in_q[e.u])
						q.push( { d[e.u][i + e.h], e.u }), in_q[e.u] = true;
				}
	}
	for (int i = 0; i < k; i++)
		min_p = min(d[b][i], min_p);
	std::cout << (min_p == 1e9 ? -1 : min_p);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int k, m, a, b;
	std::cin >> k >> n >> m, adj.resize(n);

	for (int i = 0, v, u, t, h; i < m; i++) {
		std::cin >> v >> u >> t >> h, v--, u--;
		adj[v].push_back(edge(u, t, h));
		adj[u].push_back(edge(v, t, h));
	}

	std::cin >> a >> b, dijkstra(k, a - 1, b - 1);
}

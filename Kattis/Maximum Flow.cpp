/*
 * Maximum Flow.cpp
 */
#include <iostream>
#include <vector>
#include <queue>

typedef std::vector<int> vi;

int n;
std::vector<vi> cap, adj, add;

int bfs(int s, int t, std::vector<int> &p) {
	std::fill(p.begin(), p.end(), -1);
	std::queue<std::pair<int, int>> q;

	p[s] = -2;
	int min_flow = 1e9, v, w;

	q.push( { s, 1e9 });

	while (!q.empty()) {
		v = q.front().first, w = q.front().second, q.pop();

		for (int next : adj[v])
			if (p[next] == -1 && cap[v][next]) {
				p[next] = v, min_flow = std::min(w, cap[v][next]);
				if (next == t)
					return min_flow;
				q.push( { next, min_flow });
			}
	}
	return 0;
}

int max_flow(int s, int t) {
	int flow = 0, new_flow, cur, prev;
	std::vector<int> p(n);

	while ((new_flow = bfs(s, t, p)) != 0) {
		flow += new_flow, cur = t;

		while (cur != s) {
			prev = p[cur];
			cap[prev][cur] -= new_flow;
			cap[cur][prev] += new_flow;
			add[prev][cur] += new_flow;
			add[cur][prev] -= new_flow;
			cur = prev;
		}
	}
	return flow;
}

int main() {
	int num_edges, source, sink, max_f;
	std::vector<std::pair<int, int>> out;

	std::cin >> n >> num_edges >> source >> sink;
	adj.resize(n), cap.assign(n, vi(n, 0)), add.assign(n, vi(n, 0));

	for (int i = 0, u, v, w; i < num_edges; i++) {
		std::cin >> u >> v >> w;
		cap[u][v] = w;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	max_f = max_flow(source, sink);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (add[i][j] > 0)
				out.push_back( { i, j });

	std::cout << n << " " << max_f << " " << out.size() << "\n";
	for (auto i : out)
		printf("%d %d %d\n", i.first, i.second, add[i.first][i.second]);
}

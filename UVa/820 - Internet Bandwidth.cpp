/*
 * 820 - Internet Bandwidth.cpp
 */
#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

int n;
std::vector<std::vector<int>> capacity, adj;

int bfs(int s, int t, std::vector<int>& parent) {
	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	std::queue<std::pair<int, int>> q;
	q.push( { s, INF });

	int cur, flow, new_flow;
	while (!q.empty()) {
		cur = q.front().first, flow = q.front().second;
		q.pop();

		for (int next : adj[cur])
			if (parent[next] == -1 && capacity[cur][next]) {
				parent[next] = cur;
				new_flow = std::min(flow, capacity[cur][next]);
				if (next == t)
					return new_flow;
				q.push( { next, new_flow });
			}
	}
	return 0;
}

int maxflow(int s, int t) {
	int flow = 0, new_flow;
	std::vector<int> parent(n);

	int cur, prev;
	while ((new_flow = bfs(s, t, parent)) != 0) {
		flow += new_flow, cur = t;
		while (cur != s) {
			prev = parent[cur];
			capacity[prev][cur] -= new_flow;
			capacity[cur][prev] += new_flow;
			cur = prev;
		}
	}

	return flow;
}

int main() {
	int num_edges, s, t, test_case = 1;
	while (std::cin >> n && n != 0) {
		std::cin >> s >> t >> num_edges;

		capacity.assign(n, std::vector<int>(n, 0));
		adj.clear(), adj.resize(n);

		for (int i = 0, a, b, w; i < num_edges; i++) {
			std::cin >> a >> b >> w, a--, b--;
			capacity[a][b] += w, capacity[b][a] += w;
			adj[a].push_back(b), adj[b].push_back(a);
		}
		printf("Network %d\n", test_case++);
		printf("The bandwidth is %d.\n\n", maxflow(s - 1, t - 1));
	}
}

/*
 * 10986 - Sending email.cpp
 */
#include <iostream>
#include <vector>
#include <queue>

typedef std::pair<int, int> pii;
typedef std::vector<pii> vi;
typedef std::vector<vi> vii;

vii adj_list;
int nodes, s, d;

int dijkstra() {
	std::vector<int> dist(nodes, 1e9);
	std::priority_queue<pii, vi, std::greater<pii>> pq;

	pq.push(pii(0, s)), dist[s] = 0;

	int v, w;
	while (!pq.empty()) {
		v = pq.top().second, w = pq.top().first, pq.pop();
		if (w != dist[v])
			continue;
		for (auto edge : adj_list[v])
			if (dist[v] + edge.first < dist[edge.second]) {
				dist[edge.second] = dist[v] + edge.first;
				pq.push(pii(dist[edge.second], edge.second));
			}
	}
	if (dist[d] == 1e9)
		return -1;
	return dist[d];
}

int main() {
	int num_cases;
	std::cin >> num_cases;
	for (int i = 1; i <= num_cases; i++) {
		int connections;
		std::cin >> nodes >> connections >> s >> d;
		adj_list.clear(), adj_list.resize(nodes);

		int v, u, w;
		while (connections--) {
			std::cin >> v >> u >> w;
			adj_list[v].push_back(pii(w, u));
			adj_list[u].push_back(pii(w, v));
		}

		int dijk = dijkstra();
		if (dijk == -1)
			printf("Case #%d: unreachable\n", i);
		else
			printf("Case #%d: %d\n", i, dijk);
	}
}

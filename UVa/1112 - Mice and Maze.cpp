/*
 * 1112 - Mice and Maze.cpp
 */
#include <iostream>
#include <vector>
#include <queue>

typedef std::pair<int, int> pii;
typedef std::vector<pii> vi;
typedef std::vector<vi> vii;

vii adj_list;
int num_cells, exit_cell, time_limit, num_connections;
bool first = false;

void dijkstra() {
	std::vector<int> d(num_cells, 1e9);
	std::priority_queue<pii, vi, std::greater<pii>> pq;

	pq.push(pii(0, exit_cell));
	d[exit_cell] = 0;

	int v, to_v, to_w;
	while (!pq.empty()) {
		v = pq.top().second, pq.pop();
		for (auto edge : adj_list[v]) {
			to_v = edge.second, to_w = edge.first;
			if (d[v] + to_w < d[to_v])
				d[to_v] = d[v] + to_w, pq.push(pii(d[to_v], to_v));
		}
	}
	int count = 0;
	for (auto i : d)
		if (i <= time_limit)
			count++;
	std::cout << (first == true ? "\n" : ""), first = true;
	std::cout << count << "\n";
}

int main() {
	int tc;
	std::cin >> tc;
	while (tc--) {
		scanf("%d %d %d %d", &num_cells, &exit_cell, &time_limit,
				&num_connections);
		exit_cell--, adj_list.clear(), adj_list.resize(num_cells);
		int v, u, w;
		while (num_connections--) {
			std::cin >> v >> u >> w, v--, u--;
			adj_list[u].push_back(pii(w, v));
		}
		dijkstra();
	}
}

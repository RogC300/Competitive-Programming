/*
 * 929 - Number Maze.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;

std::vector<std::vector<int>> graph, dist;
int r, c;

int adj_y[4] = { 1, -1, 0, 0 };
int adj_x[4] = { 0, 0, -1, 1 };

bool valid(int y, int x) {
	if (y < 0 || y >= r || x < 0 || x >= c)
		return false;
	return true;
}

void dijkstra() {
	std::priority_queue<iii, std::vector<iii>, std::greater<iii>> pq;
	std::vector<int> rowInit(c, 1e9);
	int y, x, w, nY, nX;

	dist.clear(), dist.assign(r, rowInit);
	pq.push(iii(graph[0][0], ii(0, 0)));
	dist[0][0] = graph[0][0];

	while (!pq.empty()) {
		y = pq.top().second.first, x = pq.top().second.second;
		w = pq.top().first, pq.pop();
		for (int i = 0; i < 4; i++) {
			nY = y + adj_y[i], nX = x + adj_x[i];
			if (valid(nY, nX) && w + graph[nY][nX] < dist[nY][nX]) {
				dist[nY][nX] = w + graph[nY][nX];
				pq.push(iii(dist[nY][nX], ii(nY, nX)));
			}
		}
	}
	printf("%d\n", dist[r - 1][c - 1]);
}

int main() {
	int tc;
	std::cin >> tc;
	while (tc--) {
		std::cin >> r >> c, graph.clear(), graph.resize(r);
		for (int i = 0; i < r; i++) {
			graph[i].resize(c);
			for (int j = 0; j < c; j++)
				std::cin >> graph[i][j];
		}
		dijkstra();
	}
}

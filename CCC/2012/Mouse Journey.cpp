/*
 * Mouse Journey.cpp
 */
#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> grid;
int r, c;

void bfs() {
	queue<pair<int, int>> q;
	vector<vector<int>> dist(r, vector<int>(c, 0));

	q.push( { 0, 0 });
	dist[0][0] = 1;
	int x, y;
	while (!q.empty()) {
		y = q.front().first, x = q.front().second, q.pop();

		if (y + 1 < r && grid[y + 1][x]) {
			if (dist[y + 1][x] == 0)
				q.push( { y + 1, x });
			dist[y + 1][x] += dist[y][x];

		}

		if (x + 1 < c && grid[y][x + 1]) {
			if (dist[y][x + 1] == 0)
				q.push( { y, x + 1 });
			dist[y][x + 1] += dist[y][x];
		}
	}
	std::cout << dist[r - 1][c - 1];
}

int main() {
	int cats;
	cin >> r >> c >> cats;
	grid.assign(r, vector<bool>(c, true));

	for (int i = 0, a, b; i < cats; i++)
		std::cin >> a >> b, grid[a - 1][b - 1] = false;
	bfs();
}

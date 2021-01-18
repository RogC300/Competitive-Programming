/*
 * RoboThieves.cpp
 */
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int r, c;
vector<vector<char>> m, orig;
vector<vector<int>> dist;

void fill_cam(int i, int j) {
	m[i][j] = 'W';
	for (int y = i; y < r && orig[y][j] != 'W'; y++)
		if (orig[y][j] == '.' || orig[y][j] == 'S')
			m[y][j] = 'W';
	for (int y = i; y >= 0 && orig[y][j] != 'W'; y--)
		if (orig[y][j] == '.' || orig[y][j] == 'S')
			m[y][j] = 'W';
	for (int x = j; x < c && orig[i][x] != 'W'; x++)
		if (orig[i][x] == '.' || orig[i][x] == 'S')
			m[i][x] = 'W';
	for (int x = j; x >= 0 && orig[i][x] != 'W'; x--)
		if (orig[i][x] == '.' || orig[i][x] == 'S')
			m[i][x] = 'W';
}

void bfs(pii start) {
	dist.assign(r, vector<int>(c, 1e9));
	if (start.first == -1)
		return;
	int c_y[4] = { 1, -1, 0, 0 }, c_x[4] = { 0, 0, 1, -1 };
	std::map<char, pii> dir = { { 'L', { 0, -1 } }, { 'R', { 0, 1 } }, { 'U', {
			-1, 0 } }, { 'D', { 1, 0 } } };

	queue<pii> q;
	pii v;
	q.push(start);
	dist[start.first][start.second] = 0;
	int y, x;

	while (!q.empty()) {
		v = q.front(), q.pop();
		char cur = m[v.first][v.second];
		int cur_d = dist[v.first][v.second];

		if (dir.find(cur) != dir.end()) {
			y = v.first + dir[cur].first;
			x = v.second + dir[cur].second;
			if (m[y][x] != 'W' && dist[y][x] > dist[v.first][v.second])
				q.push( { y, x }), dist[y][x] = cur_d;
			continue;
		}

		for (int i = 0; i < 4; i++) {
			y = v.first + c_y[i], x = v.second + c_x[i];
			if (m[y][x] != 'W' && dist[y][x] > dist[v.first][v.second] + 1)
				q.push( { y, x }), dist[y][x] = dist[v.first][v.second] + 1;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	std::cin >> r >> c;
	orig.resize(r, vector<char>(c));
	pii start;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			std::cin >> orig[i][j];
			if (orig[i][j] == 'S')
				start = { i, j };
		}
	m = orig;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (orig[i][j] == 'C')
				fill_cam(i, j);
	if (m[start.first][start.second] == 'W')
		start.first = -1;
	bfs(start);

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (orig[i][j] == '.')
				std::cout << (dist[i][j] == 1e9 ? -1 : dist[i][j]) << "\n";
}

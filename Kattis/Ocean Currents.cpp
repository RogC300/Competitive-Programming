/*
 * Ocean Currents.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
#include <map>

typedef std::vector<int> vi;
typedef std::pair<int, int> pii;

void pmv(std::vector<std::vector<int>> v) {
	for (int i = 0; i < (int) v.size(); i++)
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << (v[i][j] == 1e9 ? -1 : v[i][j])
					<< (j == (int) v[i].size() - 1 ? "\n" : " ");
	puts("");
}

bool valid(int y, int x, int r, int c) {
	return y < r && y >= 0 && x < c && x >= 0;
}

int cY[8] = { 0, 0, 1, 1, 1, -1, -1, -1 };
int cX[8] = { 1, -1, 1, 0, -1, 1, 0, -1 };
int cmd[8] = { 2, 6, 3, 4, 5, 1, 0, 7 };

int bfs(pii start, pii end, std::vector<vi> o, int r, int c) {
	std::vector<vi> d(r, vi(c, 1e9));
	d[start.first][start.second] = 0;
//	std::queue <pii> q;
	std::priority_queue<std::pair<int, pii>, std::vector<std::pair<int, pii>>,
			std::greater<std::pair<int, pii>>> q;
	q.push( { 0, start });
	int y, x;

	while (!q.empty()) {
		y = q.top().second.first, x = q.top().second.second, q.pop();
		if (pii { y, x } == end || d[y][x] >= d[end.first][end.second])
			continue;

		for (int i = 0, y1, x1, cost; i < 8; i++) {
			y1 = y + cY[i], x1 = x + cX[i];
			cost = cmd[i] == o[y][x] ? d[y][x] : d[y][x] + 1;
			if (valid(y1, x1, r, c) && cost < d[y1][x1])
				d[y1][x1] = cost, q.push( { cost, { y1, x1 } });
		}
	}
//	pmv(d);
	return d[end.first][end.second];
}

int main() {
	int r, c, trips;
	pii start, end;
	char tmp;
	std::vector<vi> ocean;

	std::cin >> r >> c, ocean.resize(r, vi(c));

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			std::cin >> tmp, ocean[i][j] = tmp - '0';

	std::cin >> trips;
	while (trips--) {
		std::cin >> start.first >> start.second >> end.first >> end.second;
		start.first -= 1, start.second -= 1, end.first -= 1, end.second -= 1;
		std::cout << bfs(start, end, ocean, r, c) << "\n";
	}
}

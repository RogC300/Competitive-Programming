/*
 * 10653 - Bombs! NO they are Mines!!.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define pair std::pair <int, int>

int rows, columns;
int change_x[4] = { 1, -1, 0, 0 };
int change_y[4] = { 0, 0, 1, -1 };

bool bound(int y, int x) {
	return (y < rows && y >= 0 && x < columns && x >= 0);
}
std::vector<std::vector<bool>> map;
int distance[1001][1001];

int bfs(pair start, pair end) {
	memset(distance, 0, sizeof distance);
	std::queue<pair> q;
	q.push(start);
	while (!q.empty()) {
		int y = q.front().first, x = q.front().second;
		if (q.front() == end)
			break;
		q.pop();

		for (int i = 0, tY, tX; i < 4; i++) {
			tY = y + change_y[i], tX = x + change_x[i];
			if (bound(tY, tX) && !map[tY][tX]) {
				q.push(std::make_pair(tY, tX));
				map[tY][tX] = true;
				distance[tY][tX] = distance[y][x] + 1;
			}
		}
	}
	return distance[end.first][end.second];
}

int main() {
	pair start, end;
	while (std::cin >> rows >> columns && (rows != 0 || columns != 0)) {
//	std::cin >> rows >> columns;
		map.clear(), map.resize(rows);
		for (int i = 0; i < rows; i++)
			map[i].resize(columns);

		int row_mines;
		std::cin >> row_mines;
		for (int i = 0, index, num_mines, mine; i < row_mines; i++) {
			std::cin >> index >> num_mines;
			while (num_mines--)
				std::cin >> mine, map[index][mine] = true;
		}
		std::cin >> start.first >> start.second >> end.first >> end.second;
		std::cout << bfs(start, end) << "\n";
	}
}

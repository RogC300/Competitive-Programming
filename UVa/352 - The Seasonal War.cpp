/*
 * 352 - The Seasonal War.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
#include <string>

std::vector<std::string> scope;
int num_eagles, n;
int changeX[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int changeY[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

void bfs(int y, int x) {
	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(y, x));
	num_eagles++;
	while (!q.empty()) {
		std::pair<int, int> coord = q.front();
		q.pop();
		scope[coord.first][coord.second] = '0';
		for (int i = 0; i < 8; i++) {
			int y = coord.first + changeY[i];
			int x = coord.second + changeX[i];
			if (y < n && x < n && y >= 0 && x >= 0 && scope[y][x] == '1')
				q.push(std::make_pair(y, x));
		}
	}
}

int main() {
	int tc = 1;
	while (std::cin >> n) {
		scope.clear(), scope.resize(n), num_eagles = 0;
		for (int i = 0; i < n; i++)
			std::cin >> scope[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (scope[i][j] == '1')
					bfs(i, j);
		printf("Image number %d contains %d war eagles.\n", tc++, num_eagles);
	}
}

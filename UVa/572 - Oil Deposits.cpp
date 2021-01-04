/*
 * 572 - Oil Deposits.cpp
 */
#include <iostream>
#include <vector>
#include <queue>

std::vector<std::string> map;
int height, width;

int dY[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dX[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void destroy(int y, int x) {
	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(y, x));
	while (!q.empty()) {
		y = q.front().first, x = q.front().second;
		map[y][x] = '*';
		q.pop();
		for (int i = 0; i < 8; i++)
			if (y + dY[i] >= 0 && y + dY[i] < height && x + dX[i] >= 0
					&& x + dX[i] < width && map[y + dY[i]][x + dX[i]] == '@')
				q.push(std::make_pair(y + dY[i], x + dX[i]));
	}
}

int main() {
	int count;
	while (std::cin >> height >> width && height != 0 && width != 0) {
		map.clear(), map.resize(height);
		for (int i = 0; i < height; i++)
			std::cin >> map[i];
		count = 0;
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				if (map[i][j] == '@')
					destroy(i, j), count++;
		std::cout << count << std::endl;
	}
}

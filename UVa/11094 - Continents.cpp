/*
 * 11094 - Continents.cpp
 */
#include <iostream>
#include <vector>
#include <queue>

std::vector<std::string> map;
int height, width;
char land;

int dY[4] = { -1, 0, 0, 1 };
int dX[4] = { 0, -1, 1, 0 };

int conquer(int y, int x) {
	std::queue<std::pair<int, int>> q;
	int land_count = 0;
	q.push(std::make_pair(y, x));
	while (!q.empty()) {
		y = q.front().first, x = q.front().second, q.pop();
		if (map[y][x] == land)
			land_count++;

		map[y][x] = '(';
		for (int i = 0, tY, tX; i < 4; i++) {
			tY = y + dY[i], tX = x + dX[i];
			if (tY >= 0 && tY < height) {
				if (tX < width && tX >= 0 && map[tY][tX] == land)
					q.push(std::make_pair(tY, tX));
				else if (tX == -1 && map[tY][width - 1] == land)
					q.push(std::make_pair(tY, width - 1));
				else if (tX == width && map[tY][0] == land)
					q.push(std::make_pair(tY, 0));
			}
		}
	}
	return land_count;
}

void p_multi_v(std::vector<std::string> v) {
	for (int i = 0; i < (int) v.size(); i++)
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << v[i][j] << (j == (int) v[i].size() - 1 ? "\n" : " ");
}

int main() {
	int y, x, max_land;
	while (std::cin >> height >> width) {
		map.clear(), map.resize(height), max_land = 0;
		for (int i = 0; i < height; i++)
			std::cin >> map[i];

		std::cin >> y >> x, land = map[y][x], conquer(y, x);
//		p_multi_v (map);
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				if (map[i][j] == land)
					max_land = std::max(max_land, conquer(i, j));

		printf("%d\n", max_land);
//		p_multi_v (map);
	}
}

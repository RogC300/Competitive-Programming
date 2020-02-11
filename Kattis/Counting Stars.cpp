/*
 * Counting Stars.cpp
 */

#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<char>> grid;

int height, width;

void destroy(int i, int j) {
	if (i < 0 || i == height || j < 0 || j == width || grid[i][j] == '#')
		return;
	else {
		grid[i][j] = '#';
		destroy(i, j + 1);
		destroy(i, j - 1);
		destroy(i + 1, j);
		destroy(i - 1, j);
	}
}
int main() {
	int count = 0, cases = 1;
	char tmp;
	while (std::cin >> height >> width) {
		count = 0;
		grid.clear();
		grid.resize(height);

		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				std::cin >> tmp, grid[i].push_back(tmp);

		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				if (grid[i][j] == '-')
					count++, destroy(i, j);

		printf("Case %d: %d\n", cases++, count);
	}
}


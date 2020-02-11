/*
 * Sheba's Amoebas.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>

std::vector<std::vector<char>> grid;

const int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dy[8] = {1, 0, -1, 0, 1, 1, -1, -1};

bool connection(int& y, int& x) {
	for (int i = 0; i < 8; i++) {
		bool isConnected = grid[y + dy[i]][x + dx[i]] == '#';

		if (isConnected) {
			x += dx[i];
			y += dy[i];
			return true;
		}
	}

	return false;
}

int main() {
	int height, width, count = 0;
	scanf("%d %d", &height, &width);
	grid.resize(height+2);

	for (int i = 0; i < height+2; i++){
		grid[i].resize(width+2);
		for (int j = 0; j < width+2; j++)
			grid[i][j] = '.';
	}
	for (int i = 1; i < height+1; i++){
		for (int j = 1; j < width+1; j++)
			std::cin >> grid[i][j];
	}


/*	for (int i = 1; i < height+1; i++){
		for (int j = 1; j < width+1; j++)
			std::cout << grid[i][j];
		std::cout << std::endl;
	}*/

	for (int i = 1; i < height+1; i++)
		for (int j = 1; j < width+1; j++)
			if (grid[i][j] == '#') {
				count++;
				int currY = i, currX = j;
				while (true) {
					if (connection(currY, currX))
						grid[currY][currX] = '.';
					else
						break;
				}
			}
	printf ("%d", count);

}

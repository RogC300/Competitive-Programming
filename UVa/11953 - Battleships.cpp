/*
 * 11953 - Battleships.cpp
 */
#include <iostream>
#include <queue>
#include <vector>

std::vector<std::string> board;
int n, alive_ships;

int dY[4] = { -1, 0, 0, 1 };
int dX[4] = { 0, -1, 1, 0 };

void alive(int y, int x) {
	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(y, x));
	while (!q.empty()) {
		y = q.front().first, x = q.front().second, q.pop();
		board[y][x] = '.';
		for (int i = 0, tY, tX; i < 4; i++) {
			tY = y + dY[i], tX = x + dX[i];
			if (tY < n && tY >= 0 && tX < n && tX >= 0
					&& (board[tY][tX] == 'x' || board[tY][tX] == '@'))
				q.push(std::make_pair(tY, tX));
		}
	}
}

int main() {
	int tc;
	std::cin >> tc;
	for (int test_case = 1; test_case <= tc; test_case++) {
		std::cin >> n, board.resize(n), alive_ships = 0;
		for (int i = 0; i < n; i++)
			std::cin >> board[i];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (board[i][j] == 'x')
					alive(i, j), alive_ships++;
		printf("Case %d: %d\n", test_case, alive_ships);
	}
}

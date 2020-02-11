/*
 * Peg Game for Two.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

std::map<std::pair<vvi, bool>, int> memo;

int c_x[6] = { 1, -1, 0, 0, -1, 1 };
int c_y[6] = { 0, 0, 1, -1, -1, 1 };

bool valid(int y, int x) {
	return y < 5 && y >= 0 && x >= 0 && x <= y;
}

int recurse(vvi board, bool turn) {
	if (memo[ { board, turn }] > 0)
		return memo[ { board, turn }];

	int best_score = turn ? -1e9 : 1e9, temp;
	bool jump_found = false;

	for (int i = 0; i < 5; i++)
		for (int j = 0; j <= i; j++) {
			if (board[i][j] == 0)
				continue;
			for (int k = 0, y, x, y2, x2; k < 6; k++) {
				y = i + c_y[k] * 2, x = j + c_x[k] * 2;
				y2 = i + c_y[k], x2 = j + c_x[k];
				if (!valid(y, x) || board[y][x] != 0 || board[y2][x2] == 0)
					continue;
				jump_found = true;

				board[y][x] = board[i][j], temp = board[y2][x2];
				board[i][j] = 0, board[y2][x2] = 0;

				if (turn)
					best_score = std::max(best_score,
							temp * board[y][x] + recurse(board, !turn));
				else
					best_score = std::min(best_score,
							-temp * board[y][x] + recurse(board, !turn));

				board[y2][x2] = temp, board[i][j] = board[y][x], board[y][x] = 0;

			}
		}
	if (!jump_found)
		return 0;

	memo[ { board, turn }] = best_score;
	return best_score;
}

int main() {
	std::vector<vi> board(5);

	for (int i = 0; i < 5; i++)
		for (int j = 0, n; j <= i; j++)
			std::cin >> n, board[i].push_back(n);

	std::cout << recurse(board, true);
}

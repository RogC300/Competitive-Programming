/*
 * Tic Tac Toe 2.cpp
 */
#include <iostream>
#include <vector>
#include <set>

std::set<std::string> boards;

bool finished(char grid[3][3]) {
	int row, col, diag1, diag2, x = 3 * (int) 'X', o = 3 * (int) 'O';
	diag1 = (int) grid[0][0] + (int) grid[1][1] + (int) grid[2][2];
	diag2 = (int) grid[0][2] + (int) grid[1][1] + (int) grid[2][0];

	if (diag1 == o || diag2 == o || diag1 == x || diag2 == x)
		return true;

	for (int i = 0; i < 3; i++) {
		row = col = 0;
		for (int j = 0; j < 3; j++)
			row += (int) grid[i][j], col += (int) grid[j][i];

		if (row == x || row == o || col == x || col == o)
			return true;
	}
	return false;
}

std::string to_string(char grid[3][3]) {
	std::string s = "";
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			s += grid[i][j];
	return s;
}

void create_combos(char grid[3][3], bool x) {
	if (boards.count(to_string(grid)))
		return;
	boards.insert(to_string(grid));
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++)
//			std::cout << grid[i][j];
//		std::cout << "\n";
//	}
//	std::cout << "\n";
	if (finished(grid))
		return;

	char place = x ? 'X' : 'O';
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (grid[i][j] == '.') {
				grid[i][j] = place;
				create_combos(grid, !x);
				grid[i][j] = '.';
			}
}

int main() {
	char grid[3][3];
	int tc;
	std::string s;
	bool possible;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			grid[i][j] = '.';
	create_combos(grid, true);

	std::cin >> tc;
	while (tc--) {
		possible = false;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				std::cin >> grid[i][j];

		s = to_string(grid);
		if (boards.count(s))
			possible = true;
		std::cout << (possible ? "yes" : "no") << "\n";
	}
}

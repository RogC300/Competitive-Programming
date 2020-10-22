/*
 * Fix You.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int rows, columns, change, tc;
	std::cin >> tc;

	while (tc--) {
		std::vector<std::vector<char>> v;

		std::cin >> rows >> columns, change = 0;
		v.resize(rows, std::vector<char>(columns));

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				std::cin >> v[i][j];

		for (int i = 0; i < columns; i++)
			if (v[rows - 1][i] == 'D')
				change++;
		for (int i = 0; i < rows; i++)
			if (v[i][columns - 1] == 'R')
				change++;

		std::cout << change << "\n";
	}
}

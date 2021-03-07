/*
 * Boboniu Plays Chess.cpp
 */
#include <iostream>

int main() {
	int row, col, r, c;

	std::cin >> row >> col >> r >> c;

	std::cout << r << " " << c << "\n";

	for (int i = 0; i < col; i++) {
		if (i + 1 == c)
			continue;
		std::cout << r << " " << i + 1 << "\n";
	}
	bool end = true;
	for (int i = 0; i < row; i++) {
		if (i + 1 == r)
			continue;

		if (end)
			for (int j = col - 1; j >= 0; j--)
				std::cout << i + 1 << " " << j + 1 << "\n";
		else
			for (int j = 0; j < col; j++)
				std::cout << i + 1 << " " << j + 1 << "\n";
		end = !end;
	}
}

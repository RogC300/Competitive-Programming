/*
 * EpigDanceOff.cpp
 */
#include <iostream>

int main() {
	int height, width, number_of_moves = 1;
	std::cin >> height >> width;
	char dance_moves[height][width];
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			std::cin >> dance_moves[y][x];
	for (int i = 0; i < width; i++) {
		bool column = true;
		for (int y = 0; y < height; y++)
			if (dance_moves[y][i] == '$') {
				column = false;
				break;
			}
		if (column)
			number_of_moves++;
	}
	std::cout << number_of_moves;
}

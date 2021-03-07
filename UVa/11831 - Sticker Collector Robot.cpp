/*
 * 11831 - Sticker Collector Robot.cpp
 */
#include <iostream>
#include <vector>
#include <map>

//		N, S, L, O
//		N, S, E, W

int posX, posY;
char direction;
std::vector<std::vector<char>> arena;
int sticker_count;
int height, width, num_commands;

std::map<char, char> right = { { 'N', 'L' }, { 'L', 'S' }, { 'S', 'O' }, { 'O',
		'N' } };
std::map<char, char> left = { { 'L', 'N' }, { 'S', 'L' }, { 'O', 'S' }, { 'N',
		'O' } };

void move() {
	switch (direction) {
	case 'N':
		if (posY - 1 >= 0 && arena[posY - 1][posX] != '#')
			posY--;
		break;
	case 'L':
		if (posX + 1 < width && arena[posY][posX + 1] != '#')
			posX++;
		break;
	case 'S':
		if (posY + 1 < height && arena[posY + 1][posX] != '#')
			posY++;
		break;
	case 'O':
		if (posX - 1 >= 0 && arena[posY][posX - 1] != '#')
			posX--;
		break;
	}
	if (arena[posY][posX] == '*')
		sticker_count++, arena[posY][posX] = '.';
}

int main() {
	char square, command;
	while (std::cin >> height >> width >> num_commands && height != 0
			&& width != 0 && num_commands != 0) {
		arena.clear(), sticker_count = 0;
		arena.resize(height);
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++) {
				std::cin >> square, arena[i].push_back(square);
				if (square == 'N' || square == 'S' || square == 'L'
						|| square == 'O')
					posX = j, posY = i, direction = square;
			}

		while (num_commands--) {
			std::cin >> command;
			if (command == 'D')
				direction = right[direction];
			else if (command == 'E')
				direction = left[direction];
			else
				move();
		}
		std::cout << sticker_count << std::endl;
	}
}


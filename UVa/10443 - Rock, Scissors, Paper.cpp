/*
 * 10443 - Rock, Scissors, Paper.cpp
 *
 *      Author: Roger
 */
#include <iostream>
#include <vector>
#include <algorithm>

int runs;
void out(std::vector<std::vector<char>> board) {
	for (int i = 0; i < (int) board.size(); i++) {
		for (int j = 0; j < (int) board[i].size(); j++)
			std::cout << board[i][j];
		printf("\n");
	}
	if (runs != 0)
		printf("\n");
}

char fight(char a, char b) {
	if (a == b)
		return ' ';
	if (a == 'R')
		return b == 'S' ? 'R' : ' ';
	else if (a == 'P')
		return b == 'R' ? 'P' : ' ';
	else if (a == 'S')
		return b == 'P' ? 'S' : ' ';
	return ' ';
}

std::vector<std::vector<char>> simulateDay(
		std::vector<std::vector<char>> board) {
	int r = board.size(), c = board[0].size();
	std::vector<std::vector<char>> temp(r);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			temp[i].push_back(' ');
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			if (i - 1 >= 0 && fight(board[i - 1][j], board[i][j]) != ' ')
				temp[i][j] = fight(board[i - 1][j], board[i][j]);
			if (i + 1 < r && fight(board[i + 1][j], board[i][j]) != ' ')
				temp[i][j] = fight(board[i + 1][j], board[i][j]);
			if (j - 1 >= 0 && fight(board[i][j - 1], board[i][j]) != ' ')
				temp[i][j] = fight(board[i][j - 1], board[i][j]);
			if (j + 1 < c && fight(board[i][j + 1], board[i][j]) != ' ')
				temp[i][j] = fight(board[i][j + 1], board[i][j]);
			if (temp[i][j] == ' ')
				temp[i][j] = board[i][j];
		}
	return temp;
}

int main() {
	std::cin >> runs;
	while (runs--) {
		int rows, columns, days;
		scanf("%d %d %d", &rows, &columns, &days);
		if (columns == 0 || rows == 0) {
			printf("\n\n");
			continue;
		}
		std::vector<std::vector<char>> board(rows);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++) {
				char temp;
				scanf(" %c", &temp);
				board[i].push_back(temp);
			}
		while (days--)
			board = simulateDay(board);
		out(board);
	}
}

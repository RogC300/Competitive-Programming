/*
 * 10284 - Chessboard in fen.cpp
 *
 *      Author: Roger
 */
// WR: FAILED TO GET ACCEPTED
#include <iostream>
#include <sstream>
#include <cstring>

char board[8][8];
int yPos, xPos;

void pawn(char piece) {
	// white uppercase
	if (islower(piece)) {
		if (yPos + 1 < 8) {
			if (board[yPos + 1][xPos] == '_')
				board[yPos + 1][xPos] = 'x';
			if (xPos + 1 < 8 && board[yPos + 1][xPos + 1] == '_')
				board[yPos + 1][xPos + 1] = 'x';
			if (xPos - 1 >= 0 && board[yPos + 1][xPos - 1] == '_')
				board[yPos + 1][xPos - 1] = 'x';
		}
	} else if (yPos - 1 >= 0) {
		if (board[yPos - 1][xPos] == '_')
			board[yPos - 1][xPos] = 'x';
		if (xPos + 1 < 8 && board[yPos + 1][xPos + 1] == '_')
			board[yPos - 1][xPos + 1] = 'x';
		if (xPos - 1 >= 0 && board[yPos + 1][xPos - 1] == '_')
			board[yPos - 1][xPos - 1] = 'x';
	}
}

void knight() {
	if (yPos + 2 < 8 && xPos + 1 < 8 && board[yPos + 2][xPos + 1] == '_')
		board[yPos + 2][xPos + 1] = 'x';
	if (yPos + 2 < 8 && xPos - 1 >= 0 && board[yPos + 2][xPos - 1] == '_')
		board[yPos + 2][xPos - 1] = 'x';
	if (yPos - 2 >= 0 && xPos + 1 < 8 && board[yPos - 2][xPos + 1] == '_')
		board[yPos - 2][xPos + 1] = 'x';
	if (yPos - 2 >= 0 && xPos - 1 >= 0 && board[yPos - 2][xPos - 1] == '_')
		board[yPos - 2][xPos - 1] = 'x';

	if (xPos + 2 < 8 && yPos + 1 < 8 && board[yPos + 1][xPos + 2] == '_')
		board[yPos + 1][xPos + 2] = 'x';
	if (xPos + 2 < 8 && yPos - 1 >= 0 && board[yPos + 1][xPos - 2] == '_')
		board[yPos + 1][xPos - 2] = 'x';
	if (xPos - 2 >= 0 && yPos + 1 < 8 && board[yPos - 1][xPos + 2] == '_')
		board[yPos - 1][xPos + 2] = 'x';
	if (xPos - 2 >= 0 && yPos - 1 >= 0 && board[yPos - 1][xPos - 2] == '_')
		board[yPos - 1][xPos - 2] = 'x';

}
void bishop() {
	int y = yPos + 1, x = xPos + 1;
	while ((board[y][x] == '_' || board[y][x] == 'x') && y < 8 && x < 8)
		board[y][x] = 'x', y += 1, x += 1;
	y = yPos - 1, x = xPos + 1;
	while ((board[y][x] == '_' || board[y][x] == 'x') && y >= 0 && x < 8)
		board[y][x] = 'x', y -= 1, x += 1;
	y = yPos + 1, x = xPos - 1;
	while ((board[y][x] == 'x' || board[y][x] == '_') && x >= 0 && y < 8)
		board[y][x] = 'x', y += 1, x -= 1;
	y = yPos -= 1, x = xPos -= 1;
	while ((board[y][x] == '_' || board[y][x] == 'x') && x >= 0 && y >= 0)
		board[y][x] = 'x', y -= 1, x -= 1;
}

void rook() {
	int y = yPos + 1, x = xPos;
	while ((board[y][x] == '_' || board[y][x] == 'x') && y < 8)
		board[y][x] = 'x', y += 1;
	y = yPos - 1, x = xPos;
	while ((board[y][x] == '_' || board[y][x] == 'x') && y >= 0)
		board[y][x] = 'x', y -= 1;
	y = yPos, x = xPos + 1;
	while ((board[y][x] == '_' || board[y][x] == 'x') && x < 8)
		board[y][x] = 'x', x += 1;
	y = yPos, x = xPos - 1;
	while ((board[y][x] == '_' || board[y][x] == 'x') && x >= 0)
		board[y][x] = 'x', x -= 1;
}

void queen() {
	rook();
	bishop();
}

void king() {
	int posX[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
	int posY[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };

	for (int i = 0; i < 8; i++) {
		int y = yPos, x = xPos;
		y += posY[i];
		x += posX[i];
		if (x >= 0 && x < 8 && y >= 0 && y < 8 && board[y][x] == '_')
			board[y][x] = 'x';
	}
}

void control(int y, int x, char piece) {
	yPos = y, xPos = x;
	if (piece == 'P' || piece == 'p')
		pawn(piece);
	piece = tolower(piece);
	if (piece == 'n')
		knight();
	if (piece == 'b')
		bishop();
	if (piece == 'r')
		rook();
	if (piece == 'q')
		queen();
	if (piece == 'k')
		king();
}

int toInt(char x) {
	std::string y = "";
	y += x;
	std::istringstream ss(y);
	int a;
	ss >> a;
	return a;
}

void drawBoard() {
	int Ycoordinate = 0;
	printf("  0 1 2 3 4 5 6 7\n");
	for (int y = 0; y < 8; y++) {
		printf("%d ", Ycoordinate);
		for (int x = 0; x < 8; x++) {
			if (board[y][x] != '_')
				printf("%c", board[y][x]);
			else
				printf("_");
			printf(" ");
		}
		printf("%d\n", Ycoordinate);
		Ycoordinate++;
	}
	printf("  0 1 2 3 4 5 6 7\n");
}

int main() {
	char fen[100];
//	scanf ("%s", fen);
	while (scanf("%s", fen) != EOF) {
		int spaces = 0, len = strlen(fen);
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				board[i][j] = '_';

		for (int i = 0, y = 0, x = 0; i < len; i++) {
			if (fen[i] == '/') {
				y++;
				continue;
			}
			if (isdigit(fen[i]))
				x += toInt(fen[i]);
			else
				board[y][x] = fen[i], x++;
			if (x == 8)
				x = 0;
		}
//		drawBoard();
		for (int y = 0; y < 8; y++)
			for (int x = 0; x < 8; x++)
				if (board[y][x] != '_')
					control(y, x, board[y][x]);

		for (int y = 0; y < 8; y++)
			for (int x = 0; x < 8; x++)
				if (board[y][x] == '_')
					spaces++;
		printf("%d\n", spaces);
//		drawBoard();
	}
}

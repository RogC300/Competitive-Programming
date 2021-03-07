/*
 * 10813 - Traditional BINGO.cpp
 *
 *      Author: Roger
 */
#include <iostream>
#include <queue>

void out(int arr[5][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			std::cout << arr[i][j] << " ";
		std::cout << "\n";
	}
	std::cout << "\n";
}

bool check(int arr[5][5]) {
	for (int i = 0; i < 5; i++) {
		int row = 0, column = 0;
		for (int j = 0; j < 5; j++) {
			row += arr[i][j];
			column += arr[j][i];
		}
		if (row == 0 || column == 0)
			return true;
	}
	int i = 0, j = 0, c = 0;
	int a = 4, b = 0, d = 0;
	while (i != 5 && j != 5) {
		c += arr[i][j];
		i++;
		j++;
		d += arr[a][b];
		a--;
		b++;
	}
	if (c == 0 || d == 0)
		return true;
	return false;
}

void add(int ball, int arr[5][5]) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (ball == arr[i][j]) {
				arr[i][j] = 0;
				return;
			}
}

int main() {
	int runs;
	std::cin >> runs;
	while (runs--) {
		std::queue<int> balls;
		int card[5][5], count = 0;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++) {
				if (i == 2 && j == 2) {
					card[i][j] = 0;
					continue;
				}
				std::cin >> card[i][j];
			}
		for (int i = 0, temp; i < 75; i++) {
			std::cin >> temp;
			balls.push(temp);
		}

		while (balls.size() != 0) {
			count++;
			add(balls.front(), card);
			balls.pop();
			if (check(card) == true) {
				printf("BINGO after %d numbers announced\n", count);
				break;
			}
		}
	}
}

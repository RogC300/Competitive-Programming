/*
 * 11085 - Back to the 8-Queens.cpp
 */
#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<int>> combo;

bool place(std::vector<int> board, int value) {
	for (int i = 0; i < (int) board.size(); i++)
		if (value == board[i] || abs(value - board[i]) == abs(i - board.size()))
			return false;
	return true;
}

void dfs(std::vector<int> board, int index) {
	if (index == 8)
		combo.push_back(board);
	else
		for (int i = 0; i < 8; i++)
			if (place(board, i)) {
				board.push_back(i);
				dfs(board, index + 1);
				board.pop_back();
			}
}

int main() {
	std::vector<int> tmp, start;
	int testCase = 1;
	dfs(tmp, 0);
	int q;
	while (std::cin >> q) {
		start.clear();
		start.push_back(q - 1);
		int min = 99999;
		for (int i = 1, q; i < 8; i++)
			std::cin >> q, start.push_back(q - 1);
		for (int i = 0; i < (int) combo.size(); i++) {
			int diff = 0;
			for (int j = 0; j < 8; j++)
				diff += (start[j] == combo[i][j] ? 0 : 1);
			min = std::min(diff, min);
		}
		printf("Case %d: %d\n", testCase++, min);
	}
}

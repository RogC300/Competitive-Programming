/*
 * Laptop Stickers.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int l, h, k;

	std::cin >> l >> h >> k;
	std::vector<std::vector<char>> v(h, std::vector<char>(l, '_'));

	char a = 'a';
	for (int i = 0, le, he, col, row; i < k; i++) {
		std::cin >> le >> he >> col >> row;
		for (int j = row; j < row + he; j++)
			for (int kk = col; kk < col + le; kk++)
				if (j >= 0 && kk >= 0 && j < h && kk < l)
					v[j][kk] = a;
		a++;
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < l; j++)
			std::cout << v[i][j];
		puts("");
	}

}


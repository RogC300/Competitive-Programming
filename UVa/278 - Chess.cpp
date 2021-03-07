/*
 * 278 - Chess.cpp
 *
 *      Author: Roger
 */
#include <iostream>
#include <algorithm>

int solve(char p, int n, int m) {
	if (p == 'r')
		return n;
	if (p == 'k') {
		if (n == 1)
			return m;
		if (n == 2)
			return m / 4 * 4 + (m % 4 == 0 ? 0 : (m % 4 == 1 ? 2 : 4));
		return (n * m + 1) / 2;
	}
	if (p == 'K') {
		if (m % 2 == 0)
			m /= 2;
		else
			m = (m + 1) / 2;

		if (n % 2 == 0)
			n /= 2;
		else
			n = (n + 1) / 2;

		return m * n;
	}
	if (p == 'Q') {
		if (n == 1)
			return 1;
		if (n == 2 && m == 2)
			return 1;
		if (n == 3 && m == 3)
			return 3;
		return n;
	}
	return -1;
}

int main() {
	int runs;
	std::cin >> runs;
	while (runs--) {
		char piece;
		int smallSide, largeSide;
		std::cin >> piece;
		std::cin >> smallSide >> largeSide;
		if (smallSide > largeSide)
			std::swap(smallSide, largeSide);

		std::cout << solve(piece, smallSide, largeSide) << std::endl;
	}
}

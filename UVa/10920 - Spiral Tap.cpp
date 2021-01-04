/*
 * 10920 - Spiral Tap.cpp
 *
 *      Author: Roger
 */
#include <iostream>
int x, y;
void solve(int size, long long int number) {
	long long int count = 1;
	int amount = 1;
	x = y = (size / 2);
	bool positive = true;
	while (true) {
		y += (positive ? amount : -1 * amount);
		count += amount;
		if (count >= number)
			do {
				if (number == count)
					return;
				y -= (positive ? 1 : -1);
			} while (count--);

		x += (positive ? -amount : amount);
		count += amount;
		if (count >= number)
			do {
				if (number == count)
					return;
				x -= (positive ? -1 : 1);
			} while (count--);
		positive = !(positive);
		amount++;
	}
}

int main() {
	while (true) {
		int size;
		long long int number;
		std::cin >> size >> number;
		if (size == 0 || number == 0)
			break;
		if (number == 1) {
			printf("Line = %d, column = %d.\n", size / 2 + 1, size / 2 + 1);
			continue;
		}
		solve(size, number);
		printf("Line = %d, column = %d.\n", y + 1, x + 1);
	}
}

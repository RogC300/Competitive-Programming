/*
 * 11565 - Simple Equations.cpp
 */
#include <iostream>

int solve() {
	int a, b, c;
	std::cin >> a >> b >> c;
	for (int x = -100; x <= 100; x++) {
		if (x == 0 || b % x != 0)
			continue;
		for (int y = x + 1; y < 100; y++) {
			int z = a - (x + y);
			if (y == 0 || b % y != 0 || z == 0 || z == x || z == y)
				continue;
			if (x * x + y * y + z * z == c && x * y * z == b
					&& x + y + z == a) {
				printf("%d %d %d\n", x, y, z);
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	int n;
	std::cin >> n;
	while (n--)
		if (solve() == 0)
			puts("No solution.");
}

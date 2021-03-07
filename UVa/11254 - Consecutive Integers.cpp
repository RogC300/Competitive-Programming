/*
 * 11254 - Consecutive Integers.cpp
 */
#include <iostream>
#include <cmath>

int main() {
	int n, a, b;
	while (std::cin >> n && n != -1) {
		a = b = n;
		for (int r = (int) sqrt(2 * n); r > 0; r--)
			if ((2 * n + r - r * r) % (2 * r) == 0) {
				a = (2 * n + r - r * r) / (2 * r), b = a + r - 1;
				break;
			}
		printf("%d = %d + ... + %d\n", n, a, b);
	}
}


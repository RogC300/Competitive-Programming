/*
 * 11231 - Black and white painting.cpp
 */
#include <iostream>
#include <cmath>

int main() {
	int n, m, w;
	while (std::cin >> n >> m >> w) {
		if (n + m + w == 0)
			break;
		n -= 7, m -= 7;
		if (w == 0)
			std::cout << (n * m) / 2 << "\n";
		else
			std::cout << (n * m + 1) / 2 << "\n";
	}
}

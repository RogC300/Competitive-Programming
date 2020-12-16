/*
 * Robot Program.cpp
 */
#include <iostream>

int main() {
	int tc, x, y;

	std::cin >> tc;

	while (tc--) {
		std::cin >> x >> y;

		if (x < y)
			std::swap(x, y);

		std::cout << (x + x - 1) + (x == y ? 1 : 0) << "\n";
	}
}

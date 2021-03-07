/*
 * XORwice.cpp
 */
#include <iostream>
#include <cmath>

int main() {
	int a, b, tc;

	std::cin >> tc;

	while (tc--) {
		std::cin >> a >> b;

		for (int i = 0; i <= 30; i++)
			if ((a >> i & 1) && (b >> i & 1))
				a -= (1 << i), b -= (1 << i);

		std::cout << a + b << "\n";
	}
}

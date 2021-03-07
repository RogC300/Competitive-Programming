/*
 * Two Arrays.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int n, unluck, tc;
	bool parity = false;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n >> unluck;

		for (int i = 0, in; i < n; i++) {
			std::cin >> in;

			if (unluck % 2 == 0 && in == unluck / 2)
				std::cout << parity << " ", parity = !parity;
			else if (in * 2 < unluck)
				std::cout << 1 << " ";
			else
				std::cout << 0 << " ";
		}
		puts("");
	}
}

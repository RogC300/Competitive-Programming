/*
 * Divisibility Problem.cpp
 */
#include <iostream>

int main() {
	int a, b, tc;
	std::cin >> tc;
	while (tc--) {
		std::cin >> a >> b;
		std::cout << (a % b == 0 ? 0 : b - (a % b)) << "\n";
	}
}

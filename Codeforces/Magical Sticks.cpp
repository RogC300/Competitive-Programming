/*
 * Magical Sticks.cpp
 */
#include <iostream>
#include <cmath>

int main() {
	int tc, n;
	std::cin >> tc;

	while (tc--)
		std::cin >> n, std::cout << (int)ceil ((double)n / 2) << "\n";
}

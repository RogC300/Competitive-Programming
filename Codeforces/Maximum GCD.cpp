/*
 * Maximum GCD.cpp
 */
#include <iostream>
#include <cmath>

int main() {
	int n, tc;
	std::cin >> tc;

	while (tc--) {
		std::cin >> n;
		std::cout << (n % 2 == 0 ? (n / 2) : ((n - 1) / 2)) << "\n";
	}
}

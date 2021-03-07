/*
 * Elimination.cpp
 */
#include <iostream>

int main() {
	int a, b, c, d, tc;
	std::cin >> tc;
	while (tc--) {
		std::cin >> a >> b >> c >> d;
		std::cout << std::max(a + b, c + d) << "\n";
	}
}

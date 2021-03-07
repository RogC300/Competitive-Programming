/*
 * FashionabLee.cpp
 */
#include <iostream>

int main() {
	int n, tc;
	std::cin >> tc;

	while (tc--)
		std::cin >> n, std::cout << (n % 4 == 0 ? "YES" : "NO") << "\n";
}

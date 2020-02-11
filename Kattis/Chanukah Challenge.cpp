/*
 * Chanukah Challenge.cpp
 *
 *      Author: tempo
 */
#include <iostream>

int main() {
	int p;
	std::cin >> p;
	while (p--) {
		int k, n;
		std::cin >> k >> n;
		std::cout << k << " " << (n * (n + 1) / 2) + n << std::endl;
	}
}

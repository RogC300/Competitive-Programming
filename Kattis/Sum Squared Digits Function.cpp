/*
 * Sum Squared Digits Function.cpp
 *
 *      Author: tempo
 */
#include <iostream>

int main() {
	int p;
	std::cin >> p;
	while (p--) {
		int k, b, n, ssd = 0;
		std::cin >> k >> b >> n;
		while (n > 0)
			ssd += (n % b) * (n % b), n /= b;
		std::cout << k << " " << ssd << "\n";
	}
}

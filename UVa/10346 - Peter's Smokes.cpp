/*
 * 10346 - Peter's Smokes.cpp
 */
#include <iostream>

int main() {
	int n, k, sum, res;
	while (std::cin >> n >> k) {
		sum = 0, res = 0;
		while (n > 0) {
			sum += n;
			res += n;
			n = res / k;
			res %= k;
		}
		std::cout << sum << "\n";
	}
}

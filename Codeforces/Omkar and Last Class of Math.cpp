/*
 * Omkar and Last Class of Math.cpp
 */
#include <iostream>

int is_prime(int n) {
	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return n / i;
	return -1;
}

int main() {
	int tc, n, p;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n;
		if (n % 2 == 0)
			std::cout << n / 2 << " " << n / 2 << "\n";
		else {
			p = is_prime(n);
			if (p == -1)
				std::cout << 1 << " " << n - 1 << "\n";
			else
				std::cout << p << " " << n - p << "\n";
		}
	}
}

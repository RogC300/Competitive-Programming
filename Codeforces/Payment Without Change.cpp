/*
 * Payment Without Change.cpp
 */
#include <iostream>

int main() {
	long long int a, b, n, s, tc;

	std::cin >> tc;

	while (tc--) {
		std::cin >> a >> b >> n >> s;
		if (s % n <= b && a * n + b >= s)
			std::cout << "YES";
		else
			std::cout << "NO";
		std::cout << "\n";
	}
}

/*
 * Fibonacci Cycles.cpp
 */
#include <iostream>
#include <unordered_map>

int main() {
	int n, tc, a, b, c, count;
	std::unordered_map<int, int> m;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n, m.clear(), a = b = 1, count = 1;
		while (1) {
			c = a + b, c %= n;
			if (m[c] != 0) {
				std::cout << m[c] << "\n";
				break;
			}
			count++, m[c] = count, a = b, b = c;
		}
	}
}

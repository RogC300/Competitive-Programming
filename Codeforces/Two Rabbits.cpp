/*
 * Two Rabbits.cpp
 */
#include <iostream>

int main() {
	int a, b, v1, v2, d, total_v, tc;

	std::cin >> tc;

	while (tc--) {
		std::cin >> a >> b >> v1 >> v2;
		d = b - a, total_v = v1 + v2;
		std::cout << (d % total_v ? -1 : d / total_v) << "\n";
	}
}

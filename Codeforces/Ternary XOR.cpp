/*
 * Ternary XOR.cpp
 */
#include <iostream>
#include <vector>
#include <cmath>

int main() {
	int n, tc;
	std::vector<int> a, b;
	char num;
	bool swap;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n, a.clear(), b.clear(), swap = false;

		for (int i = 0, in; i < n; i++) {
			std::cin >> num, in = num - '0';
			a.push_back(ceil((double) in / 2));
			b.push_back((double) in / 2);
		}
		for (int i = 0; i < n; i++) {
			std::cout << (!swap ? a[i] : 0);
			if (a[i] > b[i])
				swap = true;
		}
		puts(""), swap = false;
		for (int i = 0; i < n; i++) {
			std::cout << (!swap ? b[i] : b[i] + a[i]);
			if (a[i] > b[i])
				swap = true;
		}
		puts("");
	}
}

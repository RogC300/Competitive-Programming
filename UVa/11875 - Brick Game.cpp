/*
 * 11875 - Brick Game.cpp
 */
#include <iostream>

int main() {
	int tc;
	std::cin >> tc;
	for (int i = 1; i <= tc; i++) {
		int n, age, final;
		std::cin >> n;
		for (int j = 0; j < n; j++) {
			std::cin >> age;
			if (j == n / 2)
				final = age;
		}
		printf("Case %d: %d\n", i, final);
	}
}

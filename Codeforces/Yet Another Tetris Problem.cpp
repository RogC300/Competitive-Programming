/*
 * Yet Another Tetris Problem.cpp
 */
#include <iostream>

int main() {
	int n, tc, prev;
	bool pos;
	std::cin >> tc;

	while (tc--) {
		std::cin >> n >> prev, pos = true;
		for (int i = 0, in; i < n - 1; i++) {
			std::cin >> in;
			if (prev % 2 != in % 2)
				pos = false;
		}
		std::cout << (pos ? "YES" : "NO") << "\n";
	}
}

/*
 * Suborrays.cpp
 */
#include <iostream>

int main() {
	int n, tc;
	std::cin >> tc;

	while (tc--) {
		std::cin >> n;
		for (int i = 1; i <= n; i++)
			std::cout << i << " ";
		puts("");
	}
}

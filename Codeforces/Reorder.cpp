/*
 * Reorder.cpp
 */
#include <iostream>

int main() {
	int n, m, tc;

	std::cin >> tc;
	while (tc--) {
		std::cin >> n >> m;

		int sum = 0;
		for (int i = 0, in; i < n; i++)
			std::cin >> in, sum += in;

		std::cout << (sum == m ? "YES" : "NO") << "\n";
	}
}

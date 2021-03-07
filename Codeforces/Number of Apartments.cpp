/*
 * Number of Apartments.cpp
 */
#include <iostream>

int main() {
	int n, tc;
	std::cin >> tc;

	while (tc--) {
		std::cin >> n;
		if (n == 1 || n == 2 || n == 4)
			printf("-1\n");
		else if (n % 3 == 0)
			printf("%d 0 0\n", n / 3);
		else if (n % 3 == 2)
			printf("%d 1 0\n", (n - 5) / 3);
		else
			printf("%d 0 1\n", (n - 7) / 3);
	}
}

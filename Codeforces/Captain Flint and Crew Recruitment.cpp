/*
 * Captain Flint and Crew Recruitment.cpp
 */
#include <iostream>

int main() {
	int n, tc;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n;
		if (n > 30) {
			if (n - 30 == 6 || n - 30 == 10 || n - 30 == 14)
				printf("YES\n%d %d %d %d\n", 6, 10, 15, n - 31);
			else
				printf("YES\n%d %d %d %d\n", 6, 10, 14, n - 30);
		} else
			puts("NO");
	}
}

/*
 * String Generation.cpp
 */
#include <iostream>

int main() {
	int tc;

	std::cin >> tc;
	while (tc--) {
		int n, k;
		std::cin >> n >> k;
		char a = 'a';
		for (int i = 0; i < n; i++) {
			std::cout << a++;
			if (a == 'd')
				a = 'a';
		}
		puts("");
	}
}

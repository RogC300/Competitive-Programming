/*
 * Carousel.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n, unique, tc;
	std::vector<int> carousel;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n, carousel.resize(n);

		for (int i = 0; i < n; i++)
			std::cin >> carousel[i];

		if (std::count(carousel.begin(), carousel.end(), carousel[0]) == n) {
			std::cout << 1 << "\n";
			for (int i = 0; i < n; i++)
				std::cout << 1 << " ";
		} else if (n % 2 == 0) {
			puts("2");
			for (int i = 0; i < n; i++)
				std::cout << (i % 2) + 1 << " ";
		} else {
			unique = 0;
			for (int i = 0; i < n; i++)
				if (i == 0 || carousel[i] != carousel[i - 1])
					unique++;
			if (carousel[0] == carousel[n - 1])
				unique--;
			if (unique < n) {
				std::cout << 2 << "\n";
				bool swap = 0, done = false;

				for (int i = 0, first; i < n; i++) {
					if (i == n - 1) {
						if (carousel[i] == carousel[0] && !done)
							swap = first;
						else
							swap = !swap;
					} else if (carousel[i] == carousel[i + 1] && !done) {
						done = true;
						swap = !swap;
						std::cout << swap + 1 << " " << swap + 1 << " ";
						i += 1;
						continue;
					} else
						swap = !swap;
					std::cout << swap + 1 << " ";
					if (i == 0)
						first = swap;
				}
			} else {
				std::cout << 3 << "\n";
				for (int i = 0; i < n; i++)
					std::cout << (i == n - 1 ? 3 : i % 2 + 1) << " ";
			}
		}
		puts("");
	}
}

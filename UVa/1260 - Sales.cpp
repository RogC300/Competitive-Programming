/*
 * 1260 - Sales.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int c;
	std::cin >> c;
	while (c--) {
		int n, d, sum = 0;
		std::vector<int> l;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> d;
			if (i != 0)
				for (int j = 0; j < i; j++)
					if (l[j] <= d)
						sum++;
			l.push_back(d);
		}
		std::cout << sum << std::endl;
	}
}

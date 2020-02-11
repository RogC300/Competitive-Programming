/*
 * Distributing Ballot Boxes.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	while (true) {
		int num_city, boxes, cities[500005], lo = 1, hi = 0, mi;
		std::cin >> num_city >> boxes;
		if (num_city == -1)
			break;

		for (int i = 0; i < num_city; i++)
			std::cin >> cities[i], hi = std::max(hi, cities[i]);

		while (lo < hi) {
			mi = (lo + hi) / 2;
			int cont = 0;
			for (int i = 0; i < num_city; i++)
				cont += (cities[i] + mi - 1) / mi;
			cont > boxes ? lo = mi + 1 : hi = mi;
		}
		printf("%d\n", lo);
	}
}

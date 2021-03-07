/*
 * 12405 - Scarecrow.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int cases;
	std::cin >> cases;
	for (int j = 1; j <= cases; j++) {
		int length, count = 0;
		std::string field;
		std::cin >> length >> field;

		for (int i = 0; i < length;) {
			if (field[i] == '#')
				i++;
			else
				count++, i += 3;
		}
		printf("Case %d: %d\n", j, count);
	}
}

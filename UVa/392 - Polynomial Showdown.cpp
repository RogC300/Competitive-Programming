/*
 * 392 - Polynomial Showdown.cpp
 */
#include <iostream>
#include <vector>

void print(std::vector<int> v) {
	bool first = true;
	for (int i = 8; i >= 0; i--) {
		if (v[i] == 0)
			continue;
		if (first && v[i] < 0) {
			printf("-"), v[i] *= -1;
			first = false;
			if (i == 0) {
				printf("%d", v[i]);
				continue;
			} else if (v[i] == 1)
				printf("x");
			else
				printf("%dx", v[i]);
			if (i > 1)
				printf("^%d", i);

			continue;
		} else if (first) {
			if (i == 0) {
				printf("%d", v[i]);
				continue;
			} else if (v[i] == 1)
				printf("x");
			else
				printf("%dx", v[i]);
			if (i > 1)
				printf("^%d", i);

			first = false;
			continue;
		}
		if (v[i] < 0)
			printf(" - "), v[i] *= -1;
		else
			printf(" + ");
		if (i == 0) {
			printf("%d", v[i]);
			continue;
		} else if (v[i] == 1)
			printf("x");
		else
			printf("%dx", v[i]);
		if (i > 1)
			printf("^%d", i);
	}
	puts("");
}

int main() {
	std::vector<int> v(9);
	while (std::cin >> v[8]) {
		bool none = true;
		if (v[8] != 0)
			none = false;
		for (int i = 7; i >= 0; i--) {
			std::cin >> v[i];
			if (v[i] != 0)
				none = false;
		}
		if (none)
			puts("0");
		else
			print(v);
	}
}

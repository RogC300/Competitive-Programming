/*
 * 10660 - Citizen attention offices.cpp
 */
#include <iostream>
#include <cmath>

int distance(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}

int main() {
	int c;
	std::cin >> c;
	while (c--) {
		int n, city[25] = { 0 }, A, B, C, D, E, min = 2000000000, answer[5];
		std::cin >> n;
		for (int i = 0, a, b, value, pos; i < n; i++)
			std::cin >> a >> b >> value, pos = a * 5 + b, city[pos] = value;

		for (int a = 0; a < 25; a++)
			for (int b = a + 1; b < 25; b++)
				for (int c = b + 1; c < 25; c++)
					for (int d = c + 1; d < 25; d++)
						for (int e = d + 1; e < 25; e++) {
							int sum = 0;
							for (int i = 0; i < 25; i++) {
								A = distance(a / 5, a % 5, i / 5, i % 5)
										* city[i];
								B = distance(b / 5, b % 5, i / 5, i % 5)
										* city[i];
								C = distance(c / 5, c % 5, i / 5, i % 5)
										* city[i];
								D = distance(d / 5, d % 5, i / 5, i % 5)
										* city[i];
								E = distance(e / 5, e % 5, i / 5, i % 5)
										* city[i];
								sum += std::min(std::min(A, B),
										std::min(C, std::min(D, E)));
							}
							if (sum < min)
								min = sum, answer[0] = a, answer[1] = b, answer[2] =
										c, answer[3] = d, answer[4] = e;
						}
		for (int i = 0; i < 5; i++)
			std::cout << answer[i] << ((i == 4) ? "\n" : " ");
	}
}

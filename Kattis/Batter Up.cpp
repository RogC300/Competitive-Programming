/*
 * Batter Up.cpp
 */
#include <iostream>

int main() {
	int n, d = 0;
	std::cin >> n;
	float sum = 0;
	for (int i = 0, a; i < n; i++) {
		std::cin >> a;
		if (a != -1)
			sum += (float) a, d++;
	}
	std::cout << sum / (float) d;
}

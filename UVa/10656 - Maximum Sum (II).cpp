/*
 * 10656 - Maximum Sum (II).cpp
 */
#include <iostream>

int main() {
	int n;
	while (std::cin >> n && n != 0) {
		int sum = 0;
		bool first = true;
		for (int i = 0, number; i < n; i++) {
			std::cin >> number;
			if (number != 0)
				std::cout << (first == false ? " " : "") << number, sum +=
						number, first = false;
		}
		std::cout << (sum == 0 ? "0\n" : "\n");
	}
}

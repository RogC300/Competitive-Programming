/*
 * 488 - Triangle Wave.cpp
 */
#include <iostream>

int main() {
	int amplitude, frequency, tc;
	std::cin >> tc;

	while (tc--) {
		std::cin >> amplitude >> frequency;

		while (frequency--) {
			for (int i = 1; i <= amplitude; i++) {
				for (int j = 0; j < i; j++)
					std::cout << i;
				std::cout << "\n";
			}
			for (int i = amplitude - 1; i >= 1; i--) {
				for (int j = 0; j < i; j++)
					std::cout << i;
				std::cout << "\n";
			}
			if (frequency)
				std::cout << "\n";
		}
		if (tc)
			std::cout << "\n";
	}
}

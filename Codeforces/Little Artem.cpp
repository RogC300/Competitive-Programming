/*
 * Little Artem.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int width, height, tc;

	std::cin >> tc;

	while (tc--) {
		std::cin >> height >> width;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++)
				if (i == 0 && j == 0)
					std::cout << "W";
				else
					std::cout << "B";
			std::cout << "\n";
		}
	}
}

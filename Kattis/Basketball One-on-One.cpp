/*
 * Basketball One-on-One.cpp
 */
#include <iostream>

int main() {
	std::string line;
	std::cin >> line;
	int a = 0, b = 0;

	for (int i = 0; i < (int) line.length(); i += 2) {
		line[i] == 'A' ? a += line[i + 1] - '0' : b += line[i + 1] - '0';
		if (a >= 11 && a - b >= 2) {
			std::cout << "A";
			break;
		}
		if (b >= 11 && b - a >= 2) {
			std::cout << "B";
			break;
		}
	}
}

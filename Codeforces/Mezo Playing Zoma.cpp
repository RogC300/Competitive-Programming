/*
 * Mezo Playing Zoma.cpp
 */
#include <iostream>

int main() {
	int length, left = 0, right = 0;
	char cmd;

	std::cin >> length;

	for (int i = 0; i < length; i++)
		std::cin >> cmd, (cmd == 'L' ? left++ : right++);

	std::cout << left + right + 1;
}

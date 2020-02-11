/*
 * ABC.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> num(3);
	for (int i = 0; i < 3; i++)
		std::cin >> num[i];

	std::sort(num.begin(), num.end());

	for (int i = 0; i < 3; i++) {
		char in;
		std::cin >> in;
		std::cout << num[in - 'A'] << " ";
	}
}

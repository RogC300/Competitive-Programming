/*
 * Boss Battle.cpp
 *
 *      Author: tempo
 */
#include <iostream>

int main() {
	int numPillars;
	std::cin >> numPillars;
	if (numPillars > 2)
		std::cout << numPillars - 2;
	else
		std::cout << 1;
}

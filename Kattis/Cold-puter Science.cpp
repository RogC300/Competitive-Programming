/*
 * Cold-puter Science.cpp
 *
 *      Author: tempo
 */
#include <iostream>

int main() {
	int numTemps, amount = 0;
	std::cin >> numTemps;
	for (int i = 0, temp; i < numTemps; i++) {
		std::cin >> temp;
		if (temp < 0)
			amount++;
	}
	std::cout << amount;
}

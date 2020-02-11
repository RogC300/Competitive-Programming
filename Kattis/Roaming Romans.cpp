/*
 * Roaming Romans.cpp
 *
 *      Author: tempo
 */
#include <iostream>

int main() {
	double miles;
	std::cin >> miles;
	int out = (int) (((miles * 1000) * (5280.0 / 4854.0)) + 0.5);
	std::cout << out;
}

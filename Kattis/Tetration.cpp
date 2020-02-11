/*
 * Tetration.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
	double tetrate;
	std::cin >> tetrate;
	tetrate = pow(tetrate, 1 / tetrate);
	std::cout << std::fixed << std::setprecision(6) << tetrate;
}

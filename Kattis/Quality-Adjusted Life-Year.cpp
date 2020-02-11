/*
 * Quality-Adjusted Life-Year.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <iomanip>

int main() {
	int periods;
	std::cin >> periods;
	double total = 0;
	for (int i = 0; i < periods; i++) {
		double quality, years;
		std::cin >> quality >> years;
		total += (quality * years);
	}
	std::cout << std::fixed << std::setprecision(3) << total;
}

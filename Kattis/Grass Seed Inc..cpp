/*
 * Grass Seed Inc..cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <iomanip>

int main() {
	double metreCost, totalCost = 0;
	int lawns;
	std::cin >> metreCost >> lawns;
	for (int i = 0; i < lawns; i++) {
		double width, length;
		std::cin >> width >> length;
		totalCost += width * length;
	}
	totalCost *= metreCost;
	std::cout << std::fixed << std::setprecision(7) << totalCost;
}

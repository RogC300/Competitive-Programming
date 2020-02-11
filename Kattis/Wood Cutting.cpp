/*
 * Wood Cutting.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
	int runs;
	std::cin >> runs;
	while (runs--) {
		int numOfPeople;
		double sum = 0;
		scanf("%d", &numOfPeople);
		std::vector<int> waited(numOfPeople);

		for (int i = 0, piecesOfWood, piece; i < numOfPeople; i++) {
			std::cin >> piecesOfWood;
			for (int j = 0; j < piecesOfWood; j++) {
				std::cin >> piece;
				waited[i] += piece;
			}
		}
		std::sort(waited.begin(), waited.end());
		for (int i = 0; i < numOfPeople; i++)
			sum += waited[i] * (numOfPeople - i);

		sum /= numOfPeople;
		std::cout << std::fixed << std::setprecision(6) << sum << std::endl;
	}
}

/*
 * Heart Rate.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <iomanip>

int main() {
	int runs;
	std::cin >> runs;
	while (runs--) {
		double beats, seconds;
		std::cin >> beats >> seconds;
		double min, actual, max;
		min = (60 / seconds) * (beats - 1);
		actual = (60 / seconds) * beats;
		max = (60 / seconds) * (beats + 1);

		std::cout << std::fixed << std::setprecision(4) << min << " " << actual
				<< " " << max << std::endl;
	}
}

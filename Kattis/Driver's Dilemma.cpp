/*
 * Driver's Dilemma.cpp
 */
#include <iostream>

int main() {
	double capacity, lossPerHour, distance, MPH, MPG, max = 0;
	bool solved = false;
	scanf("%lf %lf %lf", &capacity, &lossPerHour, &distance);
	capacity /= 2;

	for (int i = 0; i < 6; i++) {
		std::cin >> MPH >> MPG;
		if (distance / MPG + (distance / MPH * lossPerHour) < capacity)
			max = std::max(MPH, max), solved = true;
	}
	if (!solved)
		printf("NO");
	else
		std::cout << "YES " << max;
}

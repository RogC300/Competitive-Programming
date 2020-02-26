/*
 * Meme Problem.cpp
 *
 *      Author: Roger
 */
#include <iostream>
#include <cmath>

int main() {
	int d, runs;
	double y, z;

	scanf("%d", &runs);

	for (int i = 0; i < runs; i++) {
		scanf("%d", &d);
		if (d == 1 || d == 2 || d == 3)
			printf("N\n");
		else {
			y = ((double) d + std::sqrt((double) d * d - 4 * d)) / 2;
			z = ((double) d - std::sqrt((double) d * d - 4 * d)) / 2;
			printf("Y %0.9lf %0.9lf\n", y, z);
		}
	}
}

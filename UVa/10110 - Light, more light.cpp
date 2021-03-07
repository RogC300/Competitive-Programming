/*
 * 10110 - Light, more light.cpp
 */
#include <iostream>
#include <cmath>

int main() {
	long long int n;
	while (std::cin >> n && n != 0) {
		if (sqrt((double) n) == (double) (long long int) sqrt(n))
			puts("yes");
		else
			puts("no");
	}
}

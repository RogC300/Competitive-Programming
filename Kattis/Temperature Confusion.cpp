/*
 * Temperature Confusion.cpp
 */
#include <iostream>
#include <string>
#include <stdlib.h>

int main() {
	int numerator, denominator;
	std::string input, a, b;
	std::cin >> input;
	for (int i = 0; i < (int) input.length(); i++)
		if (input[i] == '/')
			a.append(input, 0, i), b.append(input, i + 1, input.length() - i);

	numerator = std::stoi(a), denominator = std::stoi(b);
	numerator -= 32 * denominator;
	numerator *= 5;
	denominator *= 9;

	bool divide = true;
	while (divide) {
		divide = false;
		for (int i = 2; i <= denominator; i++)
			if (denominator % i == 0 && numerator % i == 0) {
				denominator /= i, numerator /= i;
				divide = true;
			}
	}
	printf("%d/%d", numerator, denominator);
}

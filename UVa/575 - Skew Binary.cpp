/*
 * 575 - Skew Binary.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
	std::string line;
	std::vector<int> number;
	long long sum;

	while (getline(std::cin, line) && line != "0") {
		number.clear(), sum = 0;
		for (int i = 0; i < (int) line.length(); i++)
			number.push_back(line[i] - '0');

		std::reverse(number.begin(), number.end());

		for (int i = 1; i <= (int) number.size(); i++)
			sum += number[i - 1] * (pow(2, i) - 1);

		std::cout << sum << "\n";
	}
}

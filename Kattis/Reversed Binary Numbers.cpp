/*
 * Reversed Binary Numbers.cpp
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main () {
	long long int n, sum = 0;
	std::vector <int> bin;

	std::cin >> n;
	while (n != 0) {
		if (n % 2 == 0)
			bin.push_back(0);
		else
			bin.push_back(1);
		n /= 2;
	}
//	for (int i = 0; i < (int)bin.size(); i++)
//		std::cout << bin[i] << " ";

	std::reverse (bin.begin(), bin.end());

	for (int i = 0; i < (int)bin.size(); i++)
		if (bin[i] == 1)
			sum += pow (2, i);
	std::cout << sum;
}

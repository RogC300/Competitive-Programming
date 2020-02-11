/*
 * Last Factorial Digit.cpp
 *
 *      Author: tempo
 */
#include <iostream>

int lastFactorial(int n) {
	int temp = 1;
	for (int i = 1; i <= n; i++)
		temp *= i;
	return temp % 10;
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		std::cin >> num;
		std::cout << lastFactorial(num) << std::endl;
	}
}

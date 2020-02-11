/*
 * Divide by 100...cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
	std::string num, den;
	getline(std::cin, num);
	getline(std::cin, den);
	long double zeros = (long double) den.length() - 1;
	long double dotIndex = (long double) num.length() - zeros;
//  std::cout << dotIndex;
	dotIndex--;
	int remember = dotIndex;
	for (long double i = (long double) num.length() - 1; i > dotIndex; i--) {
		if (num[i] == '0')
			num[i] = '.';
		else {
			remember = (int) i;
			break;
		}
	}
	if (dotIndex < 0) {
		dotIndex *= -1;
		std::cout << "0.";
		for (long double i = 1; i < dotIndex; i++)
			std::cout << "0";
		dotIndex *= -1;
	}
//  std::cout << remember << " " << dotIndex;
//  return 0;
	for (long double i = 0; i < (long double) num.length(); i++) {
		if (num[i] == '.')
			break;
		if (i == dotIndex && dotIndex != 0 && dotIndex != remember) {
			std::cout << num[i];
			std::cout << ".";
		} else
			std::cout << num[i];
	}
}

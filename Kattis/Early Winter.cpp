/*
 * Early Winter.cpp
 *
 *      Author: tempo
 */
#include <iostream>

int main() {
	int years, thisYear, answer = -1;
	std::cin >> years >> thisYear;
	for (int i = 0, temp; i < years; i++) {
		std::cin >> temp;
		if (temp <= thisYear) {
			answer = i;
			break;
		}
	}
	if (answer == -1)
		std::cout << "It had never snowed this early!";
	else
		std::cout << "It hadn't snowed this early in " << answer << " years!";
}

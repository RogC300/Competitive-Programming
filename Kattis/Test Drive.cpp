/*
 * Test Drive.cpp
 */
#include <iostream>

int main() {
	int a, b, c, bet_a, bet_b;

	std::cin >> a >> b >> c;

	bet_a = b - a, bet_b = c - b;

	if (bet_a == bet_b)
		std::cout << "cruised";
	else if ((bet_a < 0 && bet_b > 0) || (bet_a > 0 && bet_b < 0))
		std::cout << "turned";
	else if (abs(bet_b) > abs(bet_a))
		std::cout << "accelerated";
	else
		std::cout << "braked";
}

/*
 * Eating Out.cpp
 *
 *      Author: Roger
 */
#include <iostream>

int main() {
	int amountItems, a, b, c, itemsOrdered;
	std::cin >> amountItems >> a >> b >> c;
	itemsOrdered = a + b + c;
	if (itemsOrdered <= 2 * amountItems)
		std::cout << "possible";
	else
		std::cout << "impossible";
}

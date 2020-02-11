/*
 * Maximum Rent.cpp
 */
#include <iostream>

int main() {
	int square_foot_cost, smartbulb_cost, m, outlets;
	std::cin >> square_foot_cost >> smartbulb_cost >> m >> outlets;

	if (square_foot_cost >= smartbulb_cost)
		std::cout << (m - 1) * square_foot_cost + smartbulb_cost;
	else {
		int x = 1, y = m - 1;
		while (2 * x + y < outlets)
			x++, y--;
		std::cout << x * square_foot_cost + y * smartbulb_cost;
	}
}

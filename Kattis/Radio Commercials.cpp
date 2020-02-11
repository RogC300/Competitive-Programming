/*
 * Radio Commercials.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int num_breaks, price, max_cost = 0;
	std::vector<int> times;

	std::cin >> num_breaks >> price;

	for (int i = 0, c; i < num_breaks; i++)
		std::cin >> c, times.push_back(c);

	for (int i = 0, temp = 0; i < num_breaks; i++) {
		temp = times[i] + temp >= price ? times[i] + temp - price : 0;
		max_cost = std::max(temp, max_cost);
	}
	std::cout << max_cost;
}

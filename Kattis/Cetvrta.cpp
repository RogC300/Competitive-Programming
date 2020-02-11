/*
 * Cetvrta.cpp
 */
#include <iostream>
#include <map>

int main() {
	std::map<int, int> y, x;

	for (int i = 0, y_c, x_c; i < 3; i++)
		std::cin >> y_c >> x_c, y[y_c]++, x[x_c]++;

	for (auto i : y)
		if (i.second == 1)
			std::cout << i.first << " ";
	for (auto i : x)
		if (i.second == 1)
			std::cout << i.first;
}

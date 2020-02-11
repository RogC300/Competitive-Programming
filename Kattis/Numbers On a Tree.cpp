/*
 * Numbers On a Tree.cpp
 */
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
	int h, curr = 1;
	std::string cmd;
	std::cin >> h >> cmd;

	h = pow(2, h + 1) - 1;

	for (int i = 0; i < (int) cmd.length(); i++)
		if (cmd[i] == 'L')
			curr *= 2;
		else
			curr = curr * 2 - 1;

	std::cout << std::fixed << std::setprecision(0)
			<< h - (pow(2, (int) cmd.length() + 1) - 1) + curr;
}

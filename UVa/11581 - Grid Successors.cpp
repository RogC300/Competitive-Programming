/*
 * 11581 - Grid Successors.cpp
 *
 *      Author: Roger
 */
#include <iostream>
#include <algorithm>

int main() {
	std::string code;
	while (std::cin >> code, code != "#")
		if (next_permutation(code.begin(), code.end()))
			std::cout << code << std::endl;
		else
			std::cout << "No Successor\n";
}

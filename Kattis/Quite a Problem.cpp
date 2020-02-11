/*
 * Quite a Problem.cpp
 *
 *      Author: roger
 */
#include <iostream>
#include <string>
#include <algorithm>

int main() {
	std::string line;
	while (getline(std::cin, line)) {
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);
		if (line.find("problem") != std::string::npos)
			std::cout << "yes\n";
		else
			std::cout << "no\n";
	}
}

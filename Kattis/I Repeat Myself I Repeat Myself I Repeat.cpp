/*
 * I Repeat Myself I Repeat Myself I Repeat.cpp
 */
#include <bits/stdc++.h>

int main() {
	int count;
	std::cin >> count;
	std::cin.ignore();
	while (count--) {
		std::string line;
		getline(std::cin, line);
		int length = line.length();
		for (int i = 1; i <= length; i++) {
			std::string temp = line.substr(0, i), tempt = temp;
			for (int j = 0; j < (length / i + 1); j++)
				temp += tempt;
			std::string temp2 = temp.substr(0, length);
			if (temp2 == line) {
				std::cout << i << std::endl;
				break;
			}
		}
	}
}

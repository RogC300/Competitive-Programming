/*
 * Cryptographer's Conundrum.cpp
 */
#include <iostream>

int main() {
	std::string name, per = "PER";
	int count = 0, days = 0;
	std::cin >> name;
	for (int i = 0; i < (int) name.length(); i++) {
		if (name[i] != per[count])
			days++;
		count++, count %= 3;
	}
	std::cout << days;
}

/*
 * Apaxiaaaaaaaaaaaans!.cpp
 */
#include <iostream>

int main() {
	std::string name, convert;
	std::cin >> name, name += ' ';

	for (int i = 0; i < (int) name.size() - 1; i++) {
		convert += name[i];
		while (name[i] == name[i + 1])
			i++;
	}
	std::cout << convert;
}

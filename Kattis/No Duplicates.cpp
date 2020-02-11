/*
 * No Duplicates.cpp
 */
#include <iostream>
#include <sstream>
#include <set>

int main() {
	std::string a;
	getline(std::cin, a);
	std::set<std::string> s;

	std::stringstream l(a);
	bool y = false;

	while (l >> a) {
		if (s.count(a)) {
			y = true;
			break;
		}
		s.insert(a);
	}
	if (y)
		std::cout << "no";
	else
		std::cout << "yes";
}

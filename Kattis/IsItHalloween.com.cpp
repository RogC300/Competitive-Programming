/*
 * IsItHalloween.com.cpp
 *
 *      Author: tempo
 */
#include <iostream>

int main() {
	std::string date;
	getline(std::cin, date);
	if (date == "OCT 31" || date == "DEC 25")
		std::cout << "yup";
	else
		std::cout << "nope";
}

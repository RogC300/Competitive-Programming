/*
 * Hissing Microphone.cpp
 *
 *      Author: tempo
 */
#include <iostream>

int main() {
	std::string line;
	getline (std::cin, line);
	bool hiss = false;
	for (int i = 0; i < (int)line.length()-1; i++)
		if (line[i] == 's' && line[i+1] == 's')
			hiss = true;
	if (hiss) std::cout << "hiss";
	else std::cout << "no hiss";
}


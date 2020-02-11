/*
 * DRM Messages.cpp
 *
 *      Author: tempo
 */
#include <iostream>

int main() {
	std::string line;
	getline (std::cin, line);
	int first = 0, second = 0, length = line.length(), half = length/2;

	for (int i = 0; i < half; i++)
		first += line[i]-65;
	for (int i = half; i < length; i++)
		second += line[i]-65;
	while (first > 26) first -= 26;
	while (second > 26) second -= 26;

	for (int i = 0; i < half; i++){
		line[i] += first;
		if (line[i] > 90) line[i] -= 26;
	}
	for (int i = half; i < length; i++){
		line[i] += second;
		if (line[i] > 90) line[i] -= 26;
	}

	for (int i = 0; i < half; i++){
		line[i] += line[i+half]-65;
		if (line[i] > 90) line[i] -= 26;
		std::cout << line[i];
	}


}


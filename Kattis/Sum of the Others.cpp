/*
 * Sum of the Others.cpp
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
	std::string line;
	while (getline(std::cin, line)) {
		std::string last;
		int track = 0;
		std::vector<int> numbers;
		line += ' ';
		for (int i = 0; i < (int) line.length(); i++)
			if (line[i] == ' ') {
				last = line.substr(track, i - track);
				numbers.push_back(stoi(last));
				track = i;
			}
//	for (int i = 0; i < (int)numbers.size(); i++)
//		std::cout << numbers[i] << "\n";

		for (int i = 0, sum; i < (int) numbers.size(); i++) {
			sum = 0;
			for (int j = 0; j < (int) numbers.size(); j++)
				if (j != i)
					sum += numbers[j];
			if (sum == numbers[i]) {
				std::cout << sum << "\n";
				break;
			}
		}
	}
}

/*
 * 644 - Immediate Decodability.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> codes;

bool sort_length(std::string a, std::string b) {
	return a.length() < b.length();
}

int main() {
	std::string input;
	int set = 1;

	while (std::cin >> input) {
		codes.push_back(input);
		if (input == "9") {
			std::sort(codes.begin(), codes.end(), sort_length);

			bool decodable = true;
			for (int i = 0; i < (int) codes.size(); i++)
				for (int j = i + 1; j < (int) codes.size(); j++)
					if (codes[i] == codes[j].substr(0, codes[i].length())) {
						decodable = false;
						break;
					}

			std::cout << "Set " << set++ << " is " << (decodable ? "" : "not ")
					<< "immediately decodable\n";
			codes.clear();
		}
	}
}

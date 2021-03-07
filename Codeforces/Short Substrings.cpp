/*
 * Short Substrings.cpp
 */
#include <iostream>

int main() {
	std::string in;
	int n;

	std::cin >> n;

	while (n--) {
		std::cin >> in;
		for (int i = 0; i < (int) in.length(); i += 2)
			std::cout << in[i];
		std::cout << in[in.length() - 1];
		puts("");
	}
}

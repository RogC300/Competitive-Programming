/*
 * Binary String Minimizing.cpp
 */
#include <iostream>
#include <utility>

int main() {
	int length, last_one, tc;
	long long int moves;
	std::string bin;

	std::cin >> tc;

	while (tc--) {
		std::cin >> length >> moves >> bin, last_one = 0;
		for (int i = 0; i < length; i++) {
			while (bin[last_one] == '0')
				last_one++;
			if (bin[i] == '0' && i > last_one) {
				if (i - last_one <= moves)
					std::swap(bin[last_one], bin[i]), moves -= i - last_one;
				else {
					std::swap(bin[i], bin[i - moves]);
					break;
				}
			}
		}
		std::cout << bin << "\n";
	}
}

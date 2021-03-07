/*
 * 10931 - Parity.cpp
 */
#include <iostream>
#include <algorithm>

int main() {
	int n, num_ones;
	std::string binary;

	while (std::cin >> n && n != 0) {
		num_ones = 0, binary = "";

		while (n != 0)
			num_ones += n % 2, binary += (char) (n % 2 + '0'), n /= 2;

		std::reverse(binary.begin(), binary.end());

		printf("The parity of ");
		std::cout << binary;
		printf(" is %d (mod 2).\n", num_ones);
	}
}

/*
 * Luhn's Checksum Algorithm.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int add(int n) {
	n *= 2;
	return n % 10 + n / 10;
}

int main() {
	int trials;
	std::cin >> trials;
	while (trials--) {
		std::string num;
		int sum = 0;
		std::vector<int> n;
		std::cin >> num;

		for (int i = 0; i < (int) num.length(); i++)
			n.push_back(num[i] - '0');
		std::reverse(n.begin(), n.end());
		for (int i = 1; i < (int) n.size(); i += 2)
			n[i] = add(n[i]);
		for (int i = 0; i < (int) n.size(); i++)
			sum += n[i];
		std::cout << (sum % 10 == 0 ? "PASS\n" : "FAIL\n");
	}
}

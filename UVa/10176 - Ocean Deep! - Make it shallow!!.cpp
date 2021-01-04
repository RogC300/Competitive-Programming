/*
 * 10176 - Ocean Deep! - Make it shallow!!.cpp
 */
#include <iostream>
#include <algorithm>

int main() {
	std::string binary;
	int mod = 131071, number, sum;
	char input;
	while (std::cin >> input) {
		binary = "";
		binary += input;
		while (std::cin >> input && input != '#')
			binary += input;
		binary += '#';

		sum = 0, std::reverse(binary.begin(), binary.end());
//		std::cout << binary;
		for (int i = 1; i < (int) binary.length(); i++) {
			if (binary[i] == '0')
				continue;
			number = 1;
			for (int j = 1; j < i; j++)
				number *= 2, number %= mod;
			sum += number;
		}
		if (sum % mod == 0)
			puts("YES");
		else
			puts("NO");
	}
}

/*
 * Bits.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>
#include <cmath>
std::string toBinary(int n) {
	std::string r;
	while (n != 0) {
		r = (n % 2 == 0 ? "0" : "1") + r;
		n /= 2;
	}
	return r;
}

int main() {
	int runs;
	scanf("%d", &runs);
	while (runs--) {
		int n, max = 0, currentNum = 0;
		std::cin >> n;
		std::vector<int> num;
		while (n != 0) {
			num.push_back(n % 10);
			n /= 10;
		}

		for (int i = num.size() - 1; i >= 0; i--) {
			currentNum += num[i];
			int temp = 0;
			std::string a = toBinary(currentNum);
			for (int j = 0; j < (int) a.length(); j++)
				if (a[j] == '1')
					temp++;

			max = std::max(temp, max);
			currentNum *= 10;
		}
		std::cout << max << std::endl;
	}
}

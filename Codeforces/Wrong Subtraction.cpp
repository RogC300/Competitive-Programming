/*
 * Wrong Subtraction.cpp
 */
#include <iostream>

int main() {
	int n, sub;
	std::cin >> n >> sub;

	while (sub--) {
		if (n % 10 > 0)
			n--;
		else
			n /= 10;
	}

	std::cout << n;
}

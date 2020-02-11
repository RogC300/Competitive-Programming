/*
 * Filip.cpp
 *
 *      Author: tempo
 */
#include <iostream>

int reverse(int n) {
	int rev = 0;
	while (n > 0) {
		rev += n % 10;
		n /= 10;
		rev *= 10;
	}
	return rev/10;
}

int main() {
	int a, b;
	std::cin >> a >> b;
	a = reverse(a);
	b = reverse(b);
	if (a > b)
		std::cout << a;
	else
		std::cout << b;
}

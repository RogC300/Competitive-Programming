/*
 * Don't pass me the ball!.cpp
 */
#include <iostream>

int main() {
	int n;
	std::cin >> n, n--;
	std::cout << (n * (n - 1) * (n - 2)) / 6;
}

/*
 * 11847 - Cut the Silver Bar.cpp
 */
#include <iostream>
#include <cmath>

int main() {
	int n;
	while (std::cin >> n && n != 0)
		std::cout << (int) log2(n) << "\n";
}

/*
 * Job Expenses.cpp
 */
#include <iostream>

int main() {
	int n, sum = 0;
	std::cin >> n;
	for (int i = 0, a; i < n; i++)
		std::cin >> a, a < 0 ? sum += -a : 1;
	std::cout << sum;
}

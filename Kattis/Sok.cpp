/*
 * Sok.cpp
 */
#include <iostream>
#include <iomanip>

int main() {
	double a[3], b[3], minq = 999;
	for (int i = 0; i < 3; i++)
		std::cin >> a[i];
	for (int i = 0; i < 3; i++)
		std::cin >> b[i];
	for (int i = 0; i < 3; i++)
		minq = std::min(a[i] / b[i], minq);
	for (int i = 0; i < 3; i++)
		std::cout << std::fixed << std::setprecision(6) << (a[i] - minq * b[i])
				<< " ";
}

/*
 * Mountain Biking.cpp
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

const double PI = 3.14159265;

int main() {
	int n;
	double g, sum;
	std::vector<int> d;
	std::vector<double> v;

	std::cin >> n >> g;
	for (int i = 0, a, b; i < n; i++)
		std::cin >> a >> b, d.push_back(a), v.push_back(g * cos(b * PI / 180));

	std::cout << std::fixed << std::setprecision(6);

	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = i; j < n; j++)
			sum += 2.0 * v[j] * d[j];
		std::cout << sqrt(sum) << "\n";
	}
}

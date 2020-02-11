/*
 * Reconnaissance.cpp
 */
#include <iostream>
#include <vector>
#include <iomanip>

typedef std::pair<int, int> pii;

std::vector<pii> vehicles;

double dist(double time) {
	double min = 1e9, max = -1e9, temp;
	for (int i = 0; i < (int) vehicles.size(); i++) {
		temp = vehicles[i].second * time + vehicles[i].first;
		max = std::max(temp, max);
		min = std::min(temp, min);
	}
	return max - min;
}

double ternary() {
	double l = 0, r = 100000, m1, m2, d1, d2;
	while (r - l > 0.000001) {
		m1 = l + (r - l) / 3.0, m2 = r - (r - l) / 3.0;
		d1 = dist(m1), d2 = dist(m2);
		d1 < d2 ? r = m2 : l = m1;
	}
	return dist(l);
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0, p, v; i < n; i++)
		std::cin >> p >> v, vehicles.push_back( { p, v });
	std::cout << std::fixed << std::setprecision(5) << ternary();
}

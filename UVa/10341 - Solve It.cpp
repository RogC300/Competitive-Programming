/*
 * 10341 - Solve It.cpp
 */
#include <iostream>
#include <math.h>
#include <iomanip>

double p, q, r, s, t, u;
bool sol = true;

double calc(double x) {
	return p * std::exp(-x) + q * std::sin(x) + r * std::cos(x)
			+ s * std::tan(x) + t * x * x + u;
}

double binary_search() {
	double l = 0.0, r = 1.0, m, ans;
	int count = 0;
	for (;;) {
		m = (l + r) / 2, ans = calc(m);
		if (fabs(ans) < 0.0000001)
			break;
		count++;
		if (count == 100) {
			sol = false;
			return -1.0;
		}
		ans > 0 ? l = m : r = m;
	}
	return m;
}

int main() {
	while (std::cin >> p >> q >> r >> s >> t >> u) {
		sol = true;
		double result = binary_search();
		if (sol == false)
			puts("No solution");
		else
			printf("%0.4lf\n", result);
	}
}

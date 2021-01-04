/*
 * 10773 - Back to Intermediate Math.cpp
 */
#include <iostream>
#include <cmath>

int main() {
	int tc;
	std::cin >> tc;
	for (int i = 1; i <= tc; i++) {
		int d, v, u;
		std::cin >> d >> v >> u;
		double t1 = (double) d / u;
		double t2 = (double) d / sqrt(u * u - v * v);
		if (t2 == t1 || v >= u)
			printf("Case %d: can't determine\n", i);
		else
			printf("Case %d: %.3lf\n", i, t2 - t1);
	}
}

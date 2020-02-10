/*
 * Temporarily unavailable.cpp
 */
#include <iostream>

int main() {
	int n, a, b, loc, rad, una, l, r;

	std::cin >> n;

	while (n--) {
		std::cin >> a >> b >> loc >> rad;
		if (a > b)
			std::swap(a, b);
		una = b - a;
		l = loc - rad, r = loc + rad;

		if ((r <= b && r >= a) || (l <= b && l >= a)) {
			r = std::min(r, b);
			l = std::max(l, a);
			una -= r - l;
		}
		if (a >= l && b <= r)
			una = 0;

		std::cout << (una > 0 ? una : 0) << "\n";
	}
}

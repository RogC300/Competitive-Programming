/*
 * 696 - How Many Knights.cpp
 *
 *      Author: Roger
 */
#include <iostream>
#include <algorithm>

int maxKnights(int n, int m) {
	if (n > m)
		std::swap(n, m);
	if (n == 1)
		return m;
	if (n == 2)
		return m / 4 * 4 + (m % 4 == 0 ? 0 : (m % 4 == 1 ? 2 : 4));
	return (n * m + 1) / 2;
}

int main() {
	int n, m;
	while (std::cin >> n >> m)
		if (n == 0 && m == 0)
			break;
		else
			printf("%d knights may be placed on a %d row %d column board.\n",
					maxKnights(n, m), n, m);
}

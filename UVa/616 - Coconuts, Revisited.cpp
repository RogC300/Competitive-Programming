/*
 * 616 - Coconuts, Revisited.cpp
 */
#include <iostream>
#include <cmath>

bool test(int p, int n) {
	int x;
	for (int i = 0; i < p; i++) {
		x = n % p;
		if (x != 1)
			return false;
		n--;
		n -= n / p;
	}
	if (n % p != 0)
		return false;
	return true;
}

int main() {
	int n, sol;
	while (std::cin >> n && n >= 0) {
		sol = -1;
		for (int i = 1; i <= sqrt(n) + 1; i++)
			if (test(i, n))
				sol = i;
		if (sol == -1)
			printf("%d coconuts, no solution\n", n);
		else
			printf("%d coconuts, %d people and 1 monkey\n", n, sol);
	}
}

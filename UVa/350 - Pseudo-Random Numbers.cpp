/*
 * 350 - Pseudo-Random Numbers.cpp
 */
#include <iostream>

int z, i, m;

int f(int l) {
	return (z * l + i) % m;
}

int floyd(int x0) {
	int tortoise = f(x0), hare = f(f(x0));
	while (tortoise != hare) {
		tortoise = f(tortoise);
		hare = f(f(hare));
	}
	int mu = 0;
	hare = x0;
	while (tortoise != hare) {
		tortoise = f(tortoise);
		hare = f(hare);
		mu++;
	}

	int lambda = 1;
	hare = f(tortoise);
	while (tortoise != hare) {
		hare = f(hare);
		lambda++;
	}

	return lambda;
}

int main() {
	int l, tc = 0;
	while (std::cin >> z >> i >> m >> l && z != 0)
		printf("Case %d: %d\n", ++tc, floyd(l));
}

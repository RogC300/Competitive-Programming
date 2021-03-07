/*
 * 10689 - Yet another Number Sequence.cpp
 */
#include <iostream>

int main() {
	int p[4] = { 60, 300, 1500, 15000 };
	int mod[4] = { 10, 100, 1000, 10000 };
	int a, b, n, m, tc;
	bool turn;
	std::cin >> tc;
	while (tc--) {
		scanf("%d %d %d %d", &a, &b, &n, &m), m--;
		a %= mod[m], b %= mod[m], turn = true;
		for (int i = 2; i <= n % p[m] + 1; i++)
			turn ? a += b, a %= mod[m] : b += a, b %= mod[m], turn = !turn;
		turn ? 1 : a = b;
		std::cout << a << "\n";
	}
}

/*
 * TediousLee.cpp
 */
#include <iostream>
#include <vector>

int main() {
	std::vector<int> rmb(2e6 + 5);
	rmb[1] = rmb[2] = 0, rmb[3] = 4;
	int mod = 1e9 + 7;
	for (int i = 4; i < 2e6 + 5; i++) {
		rmb[i] = 2 * rmb[i - 2], rmb[i] %= mod;
		rmb[i] += rmb[i - 1] + (i % 3 == 0 ? 4 : 0), rmb[i] %= mod;
	}
	int tc, n;
	std::cin >> tc;

	while (tc--)
		std::cin >> n, std::cout << rmb[n] << "\n";
}

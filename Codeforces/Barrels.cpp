/*
 * Barrels.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
	int n, swap;
	std::vector<long long int> b;

	std::cin >> n >> swap, b.resize(n);

	for (int i = 0; i < n; i++)
		std::cin >> b[i];

	std::sort(b.begin(), b.end());

	for (int i = n - 2; i >= n - 1 - swap; i--)
		b[i] += b[i + 1];

	std::cout << b[n - 1 - swap] << "\n";
}

int main() {
	int tc;
	std::cin >> tc;
	while (tc--)
		solve();
}

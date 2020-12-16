/*
 * Toy Blocks.cpp
 */
#include <iostream>
#include <cmath>

void solve() {
	int n, raise_to = 0;
	long long int sum = 0;

	std::cin >> n;
	for (int i = 0, in; i < n; i++) {
		std::cin >> in, sum += in;
		raise_to = std::max(raise_to, in);
	}
	raise_to = std::max(raise_to, (int) ceil((double) sum / (n - 1)));

	std::cout << (long long int) (n - 1) * raise_to - sum << "\n";
}

int main() {
	int tc;
	std::cin >> tc;

	while (tc--)
		solve();
}

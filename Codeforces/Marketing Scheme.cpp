/*
 * Marketing Scheme.cpp
 */
#include <iostream>

void solve() {
	int l, r;
	std::cin >> l >> r;

	if (2 * l > r)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
}

int main() {
	int tc;
	std::cin >> tc;

	while (tc--)
		solve();
}

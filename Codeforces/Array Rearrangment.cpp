/*
 * Array Rearrangment.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
	int n, x;
	bool possible;
	std::vector<int> a, b;

	std::cin >> n >> x, possible = true;

	for (int i = 0, in; i < n; i++)
		std::cin >> in, a.push_back(in);
	for (int i = 0, in; i < n; i++)
		std::cin >> in, b.push_back(in);
	std::sort(a.begin(), a.end());
	std::sort(b.rbegin(), b.rend());

	for (int i = 0; i < n; i++)
		if (a[i] + b[i] > x)
			possible = false;
	std::cout << (possible ? "YES" : "NO") << "\n";

}

int main() {
	int tc = 1;
	std::cin >> tc;
	while (tc--)
		solve();

}

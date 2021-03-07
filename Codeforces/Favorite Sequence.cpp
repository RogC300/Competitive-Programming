/*
 * Favorite Sequence.cpp
 */
#include <iostream>
#include <vector>

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> v(n);

	for (int i = 0; i < n; i++)
		std::cin >> v[i];

	for (int i = 0; i < n / 2; i++)
		std::cout << v[i] << " " << v[n - i - 1] << " ";

	if (n % 2 == 1)
		std::cout << v[n / 2];

	puts("");
}

int main() {
	int tc = 1;
	std::cin >> tc;
	while (tc--)
		solve();
}

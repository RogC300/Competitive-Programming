/*
 * Negative Prefixes.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
	int n;
	std::vector<int> v, lock, unlock;

	std::cin >> n;
	v.resize(n), lock.resize(n);

	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	for (int i = 0; i < n; i++) {
		std::cin >> lock[i];
		if (lock[i] == 0)
			unlock.push_back(v[i]);
	}
	std::sort(unlock.rbegin(), unlock.rend());

	int us = 0;

	for (int i = 0; i < n; i++) {
		if (lock[i] == 0)
			std::cout << unlock[us++] << " ";
		else
			std::cout << v[i] << " ";
	}
	puts("");
}

int main() {
	int tc = 1;
	std::cin >> tc;

	while (tc--)
		solve();
}

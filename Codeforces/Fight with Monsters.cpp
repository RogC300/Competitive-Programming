/*
 * Fight with Monsters.cpp
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
	int n, u, e, k, ans = 0;
	std::vector<int> v, m;

	std::cin >> n >> u >> e >> k;
	v.resize(n), m.resize(n);

	for (int i = 0; i < n; i++)
		std::cin >> v[i], v[i] %= (u + e), v[i] = (v[i] == 0 ? u + e : v[i]);

	for (int i = 0; i < n; i++)
		m[i] = (int) ceil((double) v[i] / u) - 1;

	std::sort(m.begin(), m.end());

	for (int i = 0; i < n; i++) {
		if (m[i] > k)
			break;
		k -= m[i];
		ans++;
	}
	std::cout << ans;
}

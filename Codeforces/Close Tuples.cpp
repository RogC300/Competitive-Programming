/*
 * Close Tuples.cpp
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int choose(int n, int k) {
	if (k > n)
		return 0;
	if (k * 2 > n)
		k = n - k;
	if (k == 0)
		return 1;

	int result = n;
	for (int i = 2; i <= k; ++i) {
		result *= (n - i + 1);
		result /= i;
	}
	return result;
}

void solve() {
	int n, len, dif, sum = 0;
	std::vector<int> v;
	std::map<int, int> m;

	std::cin >> n >> len >> dif, v.resize(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i], m[v[i]]++;

	std::sort(v.begin(), v.end());

	for (int i = 0, bin; i < n; i++) {
		bin = std::upper_bound(v.begin(), v.end(), v[i] + dif) - v.begin() - 1;

		if (bin - i < m)
			continue;
		int low = i + m - 1;

		for (int i = low; i <= bin; i++) {
			sum += choose ()

		}

	}
}

int main() {
	int tc = 1;

	std::cin >> tc;
	while (tc--)
		solve();
}

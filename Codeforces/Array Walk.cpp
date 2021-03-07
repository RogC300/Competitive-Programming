/*
 * Array Walk.cpp
 */
#include <iostream>
#include <vector>
#include <set>

void solve() {
	int n, k, z, sum = 0, max = 0;
	std::vector<int> v;
	std::multiset<int> m;

	std::cin >> n >> k >> z, v.resize(k + 1);

	for (int i = 0, in; i < n; i++)
		std::cin >> (i < k + 1 ? v[i] : in);
	n = k + 1;
	for (int i = 0; i < n; i++)
		sum += v[i];

	for (int i = 0, ind, tmp_mx; i <= z; i++) {
		ind = k - 2 * i, tmp_mx = 0, sum = 0;
		if (ind < 0)
			break;
		for (int j = 0; j <= ind; j++) {
			tmp_mx = std::max(tmp_mx, v[j] + v[j + 1]);
			sum += v[j];
		}
		max = std::max(max, sum + tmp_mx * i);
	}
	std::cout << max << "\n";
}

int main() {
	int tc = 1;

	std::cin >> tc;
	while (tc--)
		solve();
}

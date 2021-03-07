/*
 * Voronoi Villages.cpp
 */
#include <bits/stdc++.h>

int main() {
	int n;
	std::vector<int> v;

	std::cin >> n, v.resize(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	std::sort(v.begin(), v.end());
	double cur, min = 1e9;
	for (int i = 0; i < n - 2; i++) {
		cur = (v[i + 1] - v[i]) / 2.0;
		cur += (v[i + 2] - v[i + 1]) / 2.0;
		min = std::min(cur, min);
	}
	std::cout << std::fixed << std::setprecision(1) << min;
}

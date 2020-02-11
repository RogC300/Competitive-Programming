/*
 * Hot Hike.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n, final_t = 1e9, f_in;
	std::vector<int> v;
	std::cin >> n;

	for (int i = 0, a; i < n; i++)
		std::cin >> a, v.push_back(a);

	for (int i = 0, t; i < n - 2; i++) {
		t = std::max(v[i], v[i + 2]);
		if (t < final_t)
			final_t = t, f_in = i;
	}
	std::cout << f_in + 1 << " " << final_t;
}

/*
 * Less or Equal.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> v;
	int n, k;

	std::cin >> n >> k;
	for (int i = 0, t; i < n; i++)
		std::cin >> t, v.push_back(t);

	std::sort(v.begin(), v.end());

	if (k == 0) {
		std::cout << (v[0] - 1 < 1 ? -1 : v[0] - 1);
		return 0;
	}
	int ans = v[k - 1], low = 0;

	for (int i = 0; i < n; i++)
		if (v[i] <= ans)
			low++;

	if (low > k)
		std::cout << -1;
	else
		std::cout << (ans > 1000000000 ? 1000000000 : ans);
}

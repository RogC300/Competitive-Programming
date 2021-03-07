/*
 * Copy-paste.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int n, k, min, ans, tc;
	bool seen;
	std::vector<int> v;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n >> k;
		v.resize(n), seen = false, min = 1e9, ans = 0;

		for (int i = 0; i < n; i++)
			std::cin >> v[i], min = std::min(min, v[i]);

		for (int i = 0; i < n; i++)
			if (v[i] == min && !seen)
				seen = true;
			else
				ans += (k - v[i]) / min;

		std::cout << ans << "\n";
	}
}

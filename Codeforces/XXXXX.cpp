/*
 * XXXXX.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int n, hate, tc;
	std::vector<int> v;

	std::cin >> tc;
	while (tc--) {
		std::cin >> n >> hate, v.resize(n);

		bool no_sol = true;
		int sum = 0, l, r;
		for (int i = 0; i < n; i++) {
			std::cin >> v[i], sum += v[i];
			if (v[i] % hate != 0)
				no_sol = false;
		}
		for (int i = 0; i < n; i++)
			if (v[i] % hate != 0) {
				l = n - i - 1;
				break;
			}
		for (int i = n - 1; i >= 0; i--)
			if (v[i] % hate != 0) {
				r = n - (n - i - 1) - 1;
				break;
			}
		std::cout << (no_sol ? -1 : (sum % hate != 0 ? n : std::max(r, l)));
		puts("");
	}
}

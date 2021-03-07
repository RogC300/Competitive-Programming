/*
 * GCD Compression.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int n, tc, count;
	std::vector<int> v, even, odd;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n;
		v.resize(2 * n), even.clear(), odd.clear(), count = 0;

		for (int i = 0; i < 2 * n; i++) {
			std::cin >> v[i];
			v[i] % 2 == 0 ? even.push_back(i + 1) : odd.push_back(i + 1);
		}

		for (int i = 1; i < (int) even.size(); i += 2) {
			count++;
			if (count > n - 1)
				break;
			std::cout << even[i - 1] << " " << even[i] << "\n";
		}
		for (int i = 1; i < (int) odd.size(); i += 2) {
			count++;
			if (count > n - 1)
				break;
			std::cout << odd[i - 1] << " " << odd[i] << "\n";
		}
	}
}

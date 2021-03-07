/*
 * Even Array.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int n, even, odd, min_moves, tc;
	std::vector<int> v;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n, v.resize(n), even = odd = min_moves = 0;

		for (int i = 0, in; i < n; i++)
			std::cin >> in, in % 2 == 0 ? (v[i] = 0, even++) : (v[i] = 1, odd++);

		if ((n % 2 == 0 && even != odd) || (n % 2 == 1 && even - 1 != odd)) {
			std::cout << -1 << "\n";
			continue;
		}

		for (int i = 0; i < n; i++) {
			if (i % 2 == v[i])
				continue;
			for (int j = i + 1; j < n; j++)
				if (i % 2 == v[j] && j % 2 == v[i]) {
					std::swap(v[i], v[j]), min_moves++;
					break;
				}
		}
		std::cout << min_moves << "\n";
	}
}

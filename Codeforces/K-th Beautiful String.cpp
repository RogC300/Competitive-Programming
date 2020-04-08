/*
 * K-th Beautiful String.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int n, k, count_one, tc;
	std::vector<char> s;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n >> k, count_one = 2, s.assign(n, 'a');

		for (int i = 1; i <= n - 1 && k > i; i++)
			if (k > i)
				k -= i, count_one++;

		s[n - count_one] = 'b', s[n - k] = 'b';

		for (int i = 0; i < n; i++)
			std::cout << s[i];
		puts("");
	}
}

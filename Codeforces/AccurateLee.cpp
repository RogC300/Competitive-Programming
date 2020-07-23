/*
 * AccurateLee.cpp
 */
#include <iostream>
#include <vector>

int main() {
	std::vector<int> v;
	int n, tc, zero, one;
	bool one_zero;
	char in;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n, v.resize(n), zero = one = one_zero = 0;

		for (int i = 0; i < n; i++)
			std::cin >> in, v[i] = in - '0';

		for (int i = 0; i < n && v[i] == 0; i++)
			if (v[i] == 0)
				zero++;
		for (int i = n - 1; i >= 0 && v[i] == 1; i--)
			if (v[i] == 1)
				one++;
		for (int i = 0; i < n - 1 && !one_zero; i++)
			if (v[i] == 1 && v[i + 1] == 0)
				one_zero = true;

		while (zero--)
			std::cout << 0;
		if (one_zero)
			std::cout << 0;
		while (one--)
			std::cout << 1;
		puts("");
	}
}

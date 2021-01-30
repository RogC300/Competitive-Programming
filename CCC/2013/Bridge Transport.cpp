/*
 * Bridge Transport.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int k, n, i = 0;
	std::vector<int> t;

	std::cin >> k >> n, t.resize(n);

	for (int w = 0; i < n; i++) {
		std::cin >> t[i], w += t[i], i >= 4 ? w -= t[i - 4] : 1;
		if (w > k)
			break;
	}
	std::cout << i;
}

/*
 * High Tide, Low Tide.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::vector<int> v;

	std::cin >> n, v.resize(n);

	for (int i = 0; i < n; i++)
		std::cin >> v[i];

	std::sort(v.begin(), v.end());

	int low = n / 2 - 1, high = n / 2;
	if (n % 2 != 0)
		low++, high++;

	while (low != -1 || high != n) {
		if (low != -1)
			std::cout << v[low--] << " ";
		if (high != n)
			std::cout << v[high++] << " ";
	}
}

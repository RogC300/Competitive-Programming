/*
 * Odd-Even Subsequence.cpp
 */
#include <iostream>
#include <vector>

std::vector<int> v;
int n, k;

bool check(int limit, bool parity) {
	int length = 0;

	for (int i = 0; i < n; i++)
		if (parity || v[i] <= limit)
			length++, parity = !parity;
	return length >= k;
}

int bin_search(int low, int high) {
	int mid;
	while (low < high) {
		mid = (low + high) / 2;
		if (check(mid, false) || check(mid, true))
			high = mid;
		else
			low = mid + 1;
	}
	return low;
}

int main() {
	std::cin >> n >> k, v.resize(n);

	for (int i = 0; i < n; i++)
		std::cin >> v[i];

	std::cout << bin_search(1, 1e9);
}

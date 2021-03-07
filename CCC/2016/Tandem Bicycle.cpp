/*
 * Tandem Bicycle.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> a, b;
int n;

void max() {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += std::max(a[i], b[n - i - 1]);
	std::cout << sum;
}

void min() {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += std::max(a[i], b[i]);
	std::cout << sum;
}

int main() {
	int cmd;
	std::cin >> cmd >> n, a.resize(n), b.resize(n);

	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	for (int i = 0; i < n; i++)
		std::cin >> b[i];

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	cmd == 1 ? min() : max();
}

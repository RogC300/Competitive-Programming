/*
 * Sum Game.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int n, k = 0;
	std::vector<int> a, b;
	std::cin >> n;

	for (int i = 0, in; i < n; i++)
		std::cin >> in, a.push_back(in);
	for (int i = 0, in; i < n; i++)
		std::cin >> in, b.push_back(in);

	for (int i = 0, a_s = 0, b_s = 0; i < n; i++) {
		a_s += a[i], b_s += b[i];
		if (a_s == b_s)
			k = i + 1;
	}
	std::cout << k;
}

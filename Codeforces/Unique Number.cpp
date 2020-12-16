/*
 * Unique Number.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> solve() {
	int n;
	std::vector<int> v;
	std::cin >> n;
	if (n > 45) {
		v.push_back(-1);
		return v;
	}

	for (int i = 9; i > 0; i--) {
		if (n - i >= 0)
			n -= i, v.push_back(i);
	}
	return v;
}

int main() {
	int tc = 1;
	std::vector<int> v;
	std::cin >> tc;

	while (tc--) {
		v = solve();
		std::sort(v.begin(), v.end());
		for (auto i : v)
			std::cout << i;
		puts("");
	}
}

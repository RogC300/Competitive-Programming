/*
 * Digit Game.cpp
 */
#include <iostream>
#include <vector>

std::vector<int> v;
int n;

bool check() {
	if (n % 2 == 0) {
		for (int i = 0; i < n; i++)
			if (i % 2 == 1 && v[i] == 0)
				return 0;
		return 1;
	}
	for (int i = 0; i < n; i++)
		if (i % 2 == 0 && v[i] == 1)
			return 1;
	return 0;
}

int main() {
	int tc;
	char t;
	std::cin >> tc;
	while (tc--) {
		std::cin >> n, v.clear();
		for (int i = 0, in; i < n; i++) {
			std::cin >> t, in = (t - '0') % 2;
			v.push_back(in);
		}
		std::cout << !check() + 1 << "\n";
	}
}

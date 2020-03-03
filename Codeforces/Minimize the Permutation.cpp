/*
 * Minimize the Permutation.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int tc, n, pos = 0, num, val;
	std::vector<int> in;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n, in.resize(n), pos = 0;
		for (int i = 0; i < n; i++)
			std::cin >> in[i];

		while (pos < n) {
			num = std::min_element(in.begin() + pos, in.end()) - in.begin();
			val = in[num];
			in.erase(in.begin() + num), in.insert(in.begin() + pos, val);
			pos = std::max(num, pos + 1);
		}

		for (int i = 0; i < n; i++)
			std::cout << in[i] << " ";
		std::cout << "\n";
	}
}

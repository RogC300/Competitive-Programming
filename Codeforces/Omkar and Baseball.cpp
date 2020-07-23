/*
 * Omkar and Baseball.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

void out(std::vector<int> v) {
	for (auto i : v)
		std::cout << i << " ";
	puts("");

}

int main() {
	std::vector<int> v, sorted;
	int n, tc;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n, v.resize(n);

		for (int i = 0; i < n; i++)
			std::cin >> v[i];

		sorted = v;
		std::sort(sorted.begin(), sorted.end());

		if (sorted == v) {
			std::cout << 0 << "\n";
			continue;
		}
		bool before, after;
		for (int i = 0; i < n; i++) {
			before = after = false;
			if (v[i] == sorted[i]) {
				for (int j = i - 1; j >= 0; j--)
					if (v[j] != sorted[j]) {
						before = true;
						break;
					}
				for (int j = i + 1; j < n; j++)
					if (v[j] != sorted[j]) {
						after = true;
					}
			}
			if (after == true && before == true)
				break;
		}

		if (after == true && before == true)
			std::cout << 2 << "\n";
		else
			std::cout << 1 << "\n";
	}
}


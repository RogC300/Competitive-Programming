/*
 * Kind Anton.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int n, tc;
	std::vector<std::pair<int, int>> a;
	bool one, neg, possible;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n, a.resize(n), one = neg = false, possible = true;

		for (int i = 0; i < n; i++)
			std::cin >> a[i].first;
		for (int i = 0; i < n; i++)
			std::cin >> a[i].second;

		for (int i = 0; i < n && possible; i++) {
			if (a[i].second > a[i].first && one == false)
				possible = false;
			if (a[i].second < a[i].first && neg == false)
				possible = false;
			if (a[i].first == 1)
				one = true;
			if (a[i].first == -1)
				neg = true;
		}
		std::cout << (possible ? "YES" : "NO") << "\n";
	}
}

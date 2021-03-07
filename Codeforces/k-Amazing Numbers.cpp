/*
 * k-Amazing Numbers.cpp
 */
#include <iostream>
#include <vector>
#include <map>

int main() {
    std::ios::sync_with_stdio(false);

	int n, tc;
	std::vector<int> v;
	std::map<int, std::vector<int>> m;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n, m.clear();
		v.assign(n + 1, -1);

		for (int i = 0, in; i < n; i++) {
			std::cin >> in;
			if (m[in].size() == 0)
				m[in].push_back(0);
			m[in].push_back(i + 1);
		}
		int min = 1e9, max;
		for (auto ve : m) {
			max = 0, ve.second.push_back(n + 1);
			for (int i = 0; i < (int) ve.second.size() - 1; i++)
				max = std::max(max, ve.second[i + 1] - ve.second[i]);
			if (min > max)
				v[max] = ve.first, min = max;
		}

		for (int i = 1, cur = -1; i <= n; i++) {
			if (v[i] != cur && v[i] != -1)
				cur = v[i];
			std::cout << cur << " ";
		}
		puts ("");
	}
}

/*
 * Straights.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> v(n);
	std::vector<int> seen(10005, 0);
	int max_n = 0;
	for (int i = 0, in; i < n; i++) {
		std::cin >> in;
		v[seen[in]++].push_back(in);
		max_n = std::max(max_n, seen[in]);
	}
	for (int i = 0; i < max_n; i++)
		std::sort(v[i].begin(), v[i].end());

//	for (int i = 0; i < max_n; i++) {
//		for (auto j : v[i])
//			std::cout << j << " ";
//		puts ("");
//	}
	int count = 0;
	for (int row = 0; row < max_n; row++) {
		for (int i = 0, j; i < (int)v[row].size(); i++) {
			count++;
//			std::cout << row << "\n";
			for (j = i; j < (int)v[row].size() - 1; j++) {
				if (v[row][j + 1] == v[row][j] + 1)
					continue;
				else
					break;
			}
			i = j;
		}
	}
	std::cout << count;
}

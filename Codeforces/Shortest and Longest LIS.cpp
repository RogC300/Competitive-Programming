/*
 * Shortest and Longest LIS.cpp
 */
#include <iostream>
#include <vector>

int main() {
	std::string in;
	std::vector<int> shortest, longest;
	int n, tc;

	std::cin >> tc;
	while (tc--) {
		std::cin >> n >> in;
		shortest.resize(n), longest.resize(n);

		for (int i = 0, prev_less = 0, val = n; i < n; i++)
			if (i == n - 1 || in[i] == '>') {
				for (int j = i; j >= prev_less; j--)
					shortest[j] = val--;
				prev_less = i + 1;
			}
		for (int i = 0, prev_less = 0, val = 1; i < n; i++)
			if (i == n - 1 || in[i] == '<') {
				for (int j = i; j >= prev_less; j--)
					longest[j] = val++;
				prev_less = i + 1;
			}
		for (auto i : shortest)
			std::cout << i << " ";
		puts("");
		for (auto i : longest)
			std::cout << i << " ";
		puts("");
	}
}

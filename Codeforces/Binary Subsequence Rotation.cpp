/*
 * Binary Subsequence Rotation.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

/*
For this problem the solution is to essentially search for
the longest section of consecutive 0's or 1's
 */

int kadane(bool add, std::vector<int> v) {
	int max = 0, temp = 0;
	for (auto i : v) {
		temp += (add && i == 1) || (!add && i == 0) ? 1 : -1;
		temp = std::max(temp, 0), max = std::max(max, temp);
	}
	return abs(max);
}

int main() {
	int n;
	char c;
	std::vector<std::pair<int, int>> in;
	std::vector<int> seq;

	std::cin >> n, in.resize(n);

	for (int i = 0; i < n; i++)
		std::cin >> c, in[i].first = c - '0';
	for (int i = 0; i < n; i++)
		std::cin >> c, in[i].second = c - '0';

	for (int i = 0; i < n; i++)
		if (in[i].first != in[i].second)
			seq.push_back(in[i].first);

	if (std::count(seq.begin(), seq.end(), 0)
			!= std::count(seq.begin(), seq.end(), 1))
		std::cout << -1;
	else
		std::cout << std::max(kadane(true, seq), kadane(false, seq));
}

/*
 * XOR Inverse.cpp
 */
#include <iostream>
#include <vector>

int child = 1, trie[2][(int) 9e6];
long long int dp[2][30];
std::vector<int> loc[(int) 9e6];

void build_trie(int in, int pos) {
	for (int i = 29, v = 0, bit; i >= 0; i--) {
		bit = ((in >> i) & 1);
		if (trie[bit][v] == 0)
			trie[bit][v] = child++;
		v = trie[bit][v];
		loc[v].push_back(pos);
	}
}

void solve(int v, int bin_ind = 29) {
	int l = trie[0][v], r = trie[1][v];

	if (l)
		solve(l, bin_ind - 1);
	if (r)
		solve(r, bin_ind - 1);

	if (l == 0 || r == 0)
		return;

	int count = 0;
	long long int inversions = 0;
	for (auto zero : loc[l]) {
		while (count < (int) loc[r].size() && loc[r][count] < zero)
			count++;
		inversions += count;
	}
	dp[0][bin_ind] += inversions;
	dp[1][bin_ind] += (long long int) loc[l].size() * loc[r].size()
			- inversions;
}

int main() {
	int n;
	long long int inversions = 0, min_num = 0;

	std::cin >> n;

	for (int i = 0, in; i < n; i++)
		std::cin >> in, build_trie(in, i + 1);

	solve(0);

	for (int i = 0; i <= 29; i++) {
		inversions += std::min(dp[0][i], dp[1][i]);
		if (dp[1][i] < dp[0][i])
			min_num += (1 << i);
	}

	std::cout << inversions << " " << min_num;
}

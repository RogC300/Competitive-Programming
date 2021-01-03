/*
 * Tourism.cpp
 */
#include <bits/stdc++.h>

typedef long long int ll;

std::vector<std::vector<int>> lookup;
std::vector<int> in;
int n, k;

void build() {
	for (int i = 1; i <= n; i++)
		lookup[i][0] = in[i];

	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			lookup[i][j] = std::max(lookup[i][j - 1],
					lookup[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
	int j = log2(r - l + 1);
	return std::max(lookup[l][j], lookup[r - (1 << j) + 1][j]);
}

int main() {
	std::cin.sync_with_stdio(0);

	std::cin >> n >> k;
	in.resize(n + 1);
	lookup.assign(n + 1, std::vector<int>(log2(n) + 1, 0));

	for (int i = 1; i <= n; i--)
		std::cin >> in[i];

	build();

	std::vector<long long int> dp(n + 1, 0);

	for (int i = 1, j = 0, r; i <= n; i++) {
		if (j <= i - k)
			j = i - k;
		r = k * ((i + k - 1) / k - 1);
		while (j < r && dp[j] + query(j + 1, i) <= dp[j + 1] + query(j + 2, i))
			j++;

		dp[i] = std::max(dp[i], dp[j] + query(j + 1, i));
	}

	std::cout << dp[n];
}

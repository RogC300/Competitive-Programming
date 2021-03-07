/*
 * Balanced Trees.cpp
 */
#include <bits/stdc++.h>

std::unordered_map<int, long long int> dp;

long long int recurse(int n) {
	if (n == 1 || n == 2)
		return 1;
	if (dp.find(n) != dp.end())
		return dp[n];

	for (int i = 2; i <= n; i++) {
		if (n / i == i - 1)
			dp[n] += recurse(i - 1) * ((n / (i - 1)) - n / i);
		else
			dp[n] += recurse(n / i) + recurse(i - 1) * ((n / (i - 1)) - n / i);
		if (i >= n / i)
			break;
	}
	return dp[n];
}

int main() {
	int n;
	std::cin >> n;
	std::cout << recurse(n);
}

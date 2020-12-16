/*
 * Josh's Double Bacon Deluxe.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int n, max = 1;
	double prob;
	std::vector<int> v, last;
	std::vector<double> dp;

	std::cin >> n, v.resize(n), prob = 1.0 / n;

	for (int i = 0; i < n; i++)
		std::cin >> v[i], max = std::max(max, v[i]);
	last.resize(max + 1), dp.resize(max + 1);

	for (int i = 0; i < n; i++)
		last[v[i]] = i;

	for (int i = 0; i < n; i++) {
		if (v[i] != v[0])
			dp[v[i]] += prob;
		if (i == last[v[i]])
			prob += dp[v[i]] / (n - i);
	}

	printf("%.10f", 1.0 - dp[v[n - 1]]);
}

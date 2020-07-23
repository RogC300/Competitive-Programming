/*
 * Eugene and an array.cpp
 */
#include <iostream>
#include <vector>
#include <set>

int main() {
	int n, end = 0;
	long long int ans = 0;
	std::vector<long long int> sum;

	std::cin >> n, sum.resize(n + 1), sum[0] = 0;

	for (int i = 1; i < n + 1; i++)
		std::cin >> sum[i], sum[i] += sum[i - 1];

	std::set<long long int> seen = { 0 };

	for (int i = 0; i < n; i++) {
		while (end < n && !seen.count(sum[end + 1]))
			++end, seen.insert(sum[end]);
		ans += end - i, seen.erase(sum[i]);
	}
	std::cout << ans;
}

/*
 * By Elevator or Stairs.cpp
 */
#include <iostream>
#include <vector>

int main() {
	std::vector<std::pair<int, int>> e, dp;
	int floors, over;

	std::cin >> floors >> over;
	e.resize(floors + 1), dp.resize(floors + 1);
	dp[0].first = 0, dp[0].second = over, e[0].first = e[0].second = 0;
	for (int i = 1; i < floors; i++)
		std::cin >> e[i].first;
	for (int i = 1; i < floors; i++)
		std::cin >> e[i].second;

	for (int i = 0; i < floors - 1; i++) {
		dp[i + 1].first = std::min(dp[i].first + e[i + 1].first,
				dp[i].second + e[i + 1].first);
		dp[i + 1].second = std::min(dp[i].first + e[i + 1].second + over,
				dp[i].second + e[i + 1].second);
	}

	for (int i = 0; i < floors; i++)
		std::cout << std::min(dp[i].first, dp[i].second) << " ";
}

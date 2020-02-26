/*
 * Yet Another Division Into Teams.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n, team_number = 0;
	std::vector<std::pair<int, int>> skill;
	std::vector<long long int> dp;
	std::vector<int> p;

	std::cin >> n;
	skill.resize(n), dp.assign(n + 10, 10e9);
	p.resize(n + 10), dp[0] = 0;

	for (int i = 0; i < n; i++)
		std::cin >> skill[i].first, skill[i].second = i;
	std::sort(skill.begin(), skill.end());

//	for (int i = 0; i < n; i++)
//		std::cout << skill[i] << " ";
//	puts ("");

	for (int i = 0; i < n; i++) {
		if (dp[i] == 10e9)
			continue;

		for (int j = 3, div; j <= 5; j++) {
			div = dp[i] + skill[i + j - 1].first - skill[i].first;
			if (div < dp[i + j])
				p[i + j] = i, dp[i + j] = div;
		}
	}

//	for (int i = 0; i <= n; i++)
//		std::cout << dp[i] << " ";
//	puts ("");
//	for (int i = 0; i <= n; i++)
//		std::cout << p[i] << " ";

	int temp = n;
	while (temp != 0) {
		for (int i = temp - 1; i >= p[temp]; i--)
			skill[i].first = team_number;
		team_number++;
		temp = p[temp];
	}
//	for (int i = 0; i < n; i++)
//		std::cout << skill[i].first << " ";

	std::cout << dp[n] << " " << team_number << "\n";

	std::sort(skill.begin(), skill.end(),
			[](std::pair<int, int> a, std::pair<int, int> b) {
				return a.second < b.second;
			});
	for (int i = 0; i < n; i++)
		std::cout << skill[i].first + 1 << " ";
}

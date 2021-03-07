/*
 * Sleeping Schedule.cpp
 */
#include <iostream>
#include <vector>
#include <map>

void out(std::vector<std::map<int, int>> v) {
	for (int i = 0; i < (int) v.size(); i++) {
		for (auto j : v[i])
			std::cout << j.first << ":" << j.second << " ";
		puts("");
	}
}

int l, r;

bool in(int n) {
	return n <= r && n >= l;
}

int main() {
	int n_sleep, day_length;
	std::vector<int> wait;
	std::vector<std::map<int, int>> dp;

	std::cin >> n_sleep >> day_length >> l >> r;
	wait.resize(n_sleep);
	dp.resize(n_sleep);

	for (int i = 0; i < n_sleep; i++)
		std::cin >> wait[i];

	for (int i = -1, time; i < n_sleep - 1; i++) {
		if (i == -1) {
			dp[0][wait[0]] = in(wait[0]);
			dp[0][wait[0] - 1] = in(wait[0] - 1);
			continue;
		}
		for (auto j : dp[i]) {
			time = (j.first + wait[i + 1]) % day_length;
			dp[i + 1][time] = std::max(j.second + in(time), dp[i + 1][time]);
			time = (j.first + wait[i + 1] - 1) % day_length;
			dp[i + 1][time] = std::max(j.second + in(time), dp[i + 1][time]);
		}
	}
//	out (dp);
	int max = 0;
	for (auto i : dp[n_sleep - 1])
		max = std::max(i.second, max);

	std::cout << max;
}

/*
 * Multi-Year Contest Scheduling.cpp
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

typedef std::vector<int> vi;
typedef std::vector<vi> vii;

void pmv(vii v);

int day_of_week(int y, int d) { // 5 = Friday
	return (y + y / 4 - y / 100 + y / 400 + 6 + d) % 7;
}

void find_valid_fridays(vii &valid, int &num_years) {
	vi dates;
	for (int year = 2019; year <= 2118; year++) {
		dates.clear();
		for (int i = 1, day, fri; i <= 31; i++) {
			day = day_of_week(year, i);
			if (day == 5)
				dates.push_back(i);
			if (day == 1) {
				fri = i + 11;
				while (fri <= 31)
					dates.push_back(fri), fri += 7;
				break;
			}
		}
		valid.push_back(dates);
	}

	int num_forbidden;
	std::cin >> num_years >> num_forbidden;

	int year, month, day;
	while (num_forbidden-- && std::cin >> year >> month >> day)
		for (int i = 0; i < (int) valid[year - 2019].size(); i++)
			if (valid[year - 2019][i] == day)
				valid[year - 2019].erase(valid[year - 2019].begin() + i);
}

int dynamic_programming(vii v, int n, vii &dp) {
	for (int i = 0; i < (int) v[0].size(); i++)
		dp[0][v[0][i]] = (12 - v[0][i]) * (12 - v[0][i]);

	for (int i = 1; i < n; i++)
		for (int j = 0; j < (int) v[i].size(); j++)
			for (int k = 0, diff; k < (int) v[i - 1].size(); k++) {
				diff = (v[i][j] - v[i - 1][k]) * (v[i][j] - v[i - 1][k]);
				dp[i][v[i][j]] = std::min(dp[i - 1][v[i - 1][k]] + diff,
						dp[i][v[i][j]]);
			}
//	pmv(dp);
	int min = 1e9;
	for (int i = 0; i <= 31; i++)
		min = std::min(dp[n - 1][i], min);
	return min;
}

void find_path(vii dp, int n, vi &path) {

	int prev, min = 1e9;

	for (int i = 1; i <= 31; i++)
		if (dp[n - 1][i] < min)
			min = dp[n - 1][i], prev = i;
	path.push_back(prev);

	for (int i = n - 2; i >= 0; i--) {
		for (int j = 1; j <= 31; j++)
			if (dp[i][j] + (j - prev) * (j - prev) == min) {
				prev = j, path.push_back(prev), min = dp[i][j];
				break;
			}
	}
	std::reverse(path.begin(), path.end());

}

int main() {
	vii valid, dp(100, vi(32, 1e9));
	vi path;
	int num_years;

	find_valid_fridays(valid, num_years);
//	pmv(valid);
	std::cout << dynamic_programming(valid, num_years, dp) << "\n";
	find_path(dp, num_years, path);
	for (int i = 0; i < (int) path.size(); i++)
		std::cout << i + 2019 << " 10 " << (path[i] < 10 ? "0" : "") << path[i]
				<< "\n";
}

void pmv(std::vector<std::vector<int>> v) {
	for (int i = 0; i < (int) v.size(); i++)
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << (v[i][j] == 1e9 ? "in" : std::to_string(v[i][j]))
					<< (j == (int) v[i].size() - 1 ? "\n" : " ");
	puts("");
}

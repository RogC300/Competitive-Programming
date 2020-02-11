/*
 * Better Productivity.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> vi;
typedef std::pair<int, int> pii;

void pvi(std::vector<pii> v) {
	for (int i = 0; i < (int) v.size(); i++)
		std::cout << v[i].first << " " << v[i].second << "  ";
	puts("");

}

void pv(std::vector<std::vector<int>> v) {
	for (int i = 0; i < (int) v.size(); i++)
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << v[i][j] << (j == (int) v[i].size() - 1 ? "\n" : " ");
	printf("\n\n");
}

int main() {
	int num_workers, num_lines;
	std::vector<pii> time, bad;
	vi good;

	std::cin >> num_workers >> num_lines;

	for (int i = 0, a, b; i < num_workers; i++)
		std::cin >> a >> b, time.push_back( { a, b });

	for (int i = 0; i < num_workers; i++) {
		bool g = false;
		for (int j = 0; j < num_workers; j++)
			if (time[i].first <= time[j].first
					&& time[i].second >= time[j].second)
				if (i < j || time[i].first < time[j].first
						|| time[i].second > time[j].second)
					g = true;
		if (g)
			good.push_back(time[i].second - time[i].first);
		else
			bad.push_back( { time[i].first, time[i].second });
	}

	std::sort(bad.begin(), bad.end());
//	pvi(bad);

	std::vector<vi> dp(bad.size(), vi(num_lines, -1));
	dp[0][0] = bad[0].second - bad[0].first;

	for (int i = 1; i < (int) bad.size(); i++) {
		if (bad[i].first < bad[0].second)
			dp[i][0] = bad[0].second - bad[i].first;
		else
			dp[i][0] = -1;
	}

	for (int i = 1, l, r, best; i < num_lines; i++)
		for (int j = i; j < (int) bad.size(); j++) {
			l = bad[j].first, r = bad[j].second, best = -1;
			if (dp[j - 1][i - 1] > -1)
				best = r - l + dp[j - 1][i - 1];
			for (int k = j - 1; k >= i; k--) {
				r = bad[k].second;
				if (dp[k - 1][i - 1] == -1)
					continue;
				if (l >= r)
					break;
				best = std::max(dp[k - 1][i - 1] + r - l, best);
			}
			dp[j][i] = best;
//			pv(dp);
		}
	std::sort(good.rbegin(), good.rend());
	for (int i = 1; i < (int) good.size(); i++)
		good[i] += good[i - 1];

	int ans = dp[bad.size() - 1][num_lines - 1];

	for (int i = 0; i < (int)good.size(); i++) {
		if (num_lines - i - 2 < 0)
			break;
		if (dp[bad.size() - 1][num_lines - i - 2] == -1)
			continue;
		ans = std::max(ans, dp[bad.size() - 1][num_lines - i - 2] + good[i]);
	}
	std::cout << ans;
}

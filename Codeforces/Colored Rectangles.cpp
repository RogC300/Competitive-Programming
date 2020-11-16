/*
 * Colored Rectangles.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> vi;
typedef std::vector<vi> vii;

int main() {
	std::vector<int> r, g, b;
	int cnt_r, cnt_g, cnt_b, ans = 0;

	std::cin >> cnt_r >> cnt_g >> cnt_b;

	std::vector<vii> dp(cnt_r + 1, vii(cnt_g + 1, vi(cnt_b + 1, 0)));

	for (int i = 0, in; i < cnt_r; i++)
		std::cin >> in, r.push_back(in);
	for (int i = 0, in; i < cnt_g; i++)
		std::cin >> in, g.push_back(in);
	for (int i = 0, in; i < cnt_b; i++)
		std::cin >> in, b.push_back(in);

	std::sort(r.rbegin(), r.rend());
	std::sort(g.rbegin(), g.rend());
	std::sort(b.rbegin(), b.rend());

	dp[0][0][0] = 0;

	for (int i = 0; i < cnt_r + 1; i++)
		for (int j = 0; j < cnt_g + 1; j++)
			for (int k = 0; k < cnt_b + 1; k++) {
				if (i < cnt_r && j < cnt_g)
					dp[i + 1][j + 1][k] = std::max(dp[i + 1][j + 1][k],
							dp[i][j][k] + r[i] * g[j]);
				if (i < cnt_r && k < cnt_b)
					dp[i + 1][j][k + 1] = std::max(dp[i + 1][j][k + 1],
							dp[i][j][k] + r[i] * b[k]);
				if (j < cnt_g && k < cnt_b)
					dp[i][j + 1][k + 1] = std::max(dp[i][j + 1][k + 1],
							dp[i][j][k] + g[j] * b[k]);
				ans = std::max(ans, dp[i][j][k]);
			}

	std::cout << ans;
}

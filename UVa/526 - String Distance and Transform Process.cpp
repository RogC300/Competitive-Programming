/*
 * 526 - String Distance and Transform Process.cpp
 */
#include <iostream>

void edit_distance(std::string a, std::string b) {
	int n = a.length(), m = b.length(), cmd = 1;

	int dp[n + 1][m + 1];

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0)
				dp[i][j] = i + j;
			else if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1
						+ std::min(dp[i][j - 1],
								std::min(dp[i - 1][j], dp[i - 1][j - 1]));
		}
	std::cout << dp[n][m] << "\n";
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= m; j++)
//			std::cout << dp[i][j] << " ";
//		puts("");
//	}
//	std::cout << n << " " << m << "\n";
	while (n || m) {
		if (a[n - 1] == b[m - 1])
			n--, m--;
		else if (m > 0 && dp[n][m] == dp[n][m - 1] + 1) {
			printf("%d Insert %d,%c\n", cmd++, n + 1, b[m - 1]), m--;
			a.insert(n, 1, b[m]);
		} else if (n > 0 && dp[n][m] == dp[n - 1][m] + 1) {
			printf("%d Delete %d\n", cmd++, n), n--;
			a.erase(n, 1);
		} else if (n > 0 && m > 0) {
			printf("%d Replace %d,%c\n", cmd++, n, b[m - 1]);
			a[n - 1] = b[m - 1];
			n--, m--;
		}
	}
}

int main() {
	std::string a, b;
	bool first = false;
	while (getline(std::cin, a)) {
		getline(std::cin, b);
		std::cout << (first ? "\n" : ""), first = true;
		edit_distance(a, b);
	}
}

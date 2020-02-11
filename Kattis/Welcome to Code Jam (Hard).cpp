/*
 * Welcome to Code Jam (Hard).cpp
 */
#include <iostream>
#include <vector>

typedef long long int ll;
typedef std::vector<ll> vi;

std::string welcome = "welcome to code jam";
int n = welcome.length();

std::vector<vi> table(n + 1, vi(505, 0));
int dp(std::string b) {
	int m = b.length();

	for (int i = 0; i <= m; i++)
		table[0][i] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (welcome[i - 1] == b[j - 1])
				table[i][j] = table[i - 1][j - 1] + table[i][j - 1];
			else
				table[i][j] = table[i][j - 1];
			table[i][j] %= 10000;
		}
	return table[n][m];
}

int main() {
	std::string b;
	int tc;
	ll ans;
	std::cin >> tc;
	std::cin.ignore();
	for (int c = 1; c <= tc; c++) {
		getline(std::cin, b), ans = dp(b);
		std::string out = std::to_string(ans);
		while (out.length() < 4)
			out.insert(0, "0");
		printf("Case #%d: ", c);
		std::cout << out << "\n";
	}
}

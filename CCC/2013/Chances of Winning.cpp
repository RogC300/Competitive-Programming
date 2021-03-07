/*
 * Chances of Winning.cpp
 */
#include <bits/stdc++.h>

using namespace std;

int team[4] = { 0, 0, 0, 0 };

void recurse(vector<vector<int>> m) {
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 4; j++)
			if (m[i][j] == -1) {
				for (int k = 0; k < 3; k++)
					m[i][j] = k, recurse(m);
				return;
			}

	int s[4] = { 0, 0, 0, 0 }, mx = 0, cnt = 0, ind;
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 4; j++) {
			!m[i][j] ? s[i] += 3 : m[i][j] == 1 ? s[j] += 3 : (s[i]++, s[j]++);
			mx = max(mx, max(s[i], s[j]));
		}
	for (int i = 0; i < 4; i++)
		if (s[i] == mx)
			cnt++, ind = i;
	if (cnt == 1)
		team[ind]++;
}

int main() {
	int fav, n;

	cin >> fav >> n, fav--;
	vector<vector<int>> m(4, vector<int>(4, -1));

	for (int i = 0, a, b, s_a, s_b; i < n; i++) {
		std::cin >> a >> b >> s_a >> s_b, a--, b--;
		s_a > s_b ? m[a][b] = 0 : (s_a < s_b ? m[a][b] = 1 : m[a][b] = 2);
	}
	recurse(m), std::cout << team[fav];
}

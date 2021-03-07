/*
 * Tinted Glass Window.cpp
 */
#include <bits/stdc++.h>

using namespace std;

#define lb(a, b) lower_bound (a.begin(), a.end(), b) - a.begin()
typedef long long int ll;

int main() {
	std::ios_base::sync_with_stdio(false);
	int n, t, x_s, y_s;
	ll cnt = 0;
	vector<vector<int>> glass, rect;
	vector<int> x, y;

	std::cin >> n >> t, glass.resize(n, vector<int>(5));

	set<int> unique_x, unique_y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++)
			std::cin >> glass[i][j];
		unique_x.insert(glass[i][0]), unique_x.insert(glass[i][2]);
		unique_y.insert(glass[i][1]), unique_y.insert(glass[i][3]);
	}
	x.assign(unique_x.begin(), unique_x.end()), x_s = x.size();
	y.assign(unique_y.begin(), unique_y.end()), y_s = y.size();
	rect.assign(x_s, vector<int>(y_s, 0));

	for (auto pane : glass)
		for (int i = lb(x, pane[0]); x[i] < pane[2] && i < x_s; i++)
			for (int j = lb(y, pane[1]); y[j] < pane[3] && j < y_s; j++) {
				if (rect[i][j] == -1)
					continue;
				rect[i][j] += pane[4];
				if (rect[i][j] < t) {
					cnt += ((ll) x[i + 1] - x[i]) * (y[j + 1] - y[j]);
					rect[i][j] = -1;
				}
			}
	std::cout << cnt;
}

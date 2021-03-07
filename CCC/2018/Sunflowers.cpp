/*
 * Sunflowers.cpp
 */
#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vii;

int n;

void rotate(vii &v) {
	vii rot = v;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			rot[i][j] = v[n - j - 1][i];
	v = rot;
}

int main() {
	std::cin >> n;
	vii m(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> m[i][j];

	while (1) {
		rotate(m);
		if (m[0][0] < m[0][n - 1]
				&& m[0][n - 1] - m[0][0] < m[n - 1][n - 1] - m[n - 1][0])
			break;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			std::cout << m[i][j] << " ";
		puts("");
	}
}

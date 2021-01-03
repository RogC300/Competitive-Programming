/*
 * Triangle The Data Structure.cpp
 */

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> m, tree;
int n;

void update(int i, int j, int d) {
	for (; i < n; i = i | (i + 1))
		for (int c = j; c < n; c = c | (c + 1))
			tree[i][c] = std::max(d, tree[i][c]);
}

int max(int i, int j) {
	int ret = 0;
	for (; i >= 0; i = (i & (i + 1)) - 1)
		for (int c = j; c >= 0; c = (c & (c + 1)) - 1)
			ret = std::max(ret, tree[i][c]);
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int size;

	cin >> n >> size;
	m.assign(n, vector<int>(n, 0));
	tree.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
		for (int j = n - i - 1; j < n; j++)
			cin >> m[i][j];

	long long int sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int r = i, c = n - 1; r < n; r++, c--)
			update(r, c, m[r][c]);

		for (int r = i + size - 1, c = n - 1; r < n; r++, c--)
			sum += max(r, c);
	}
	std::cout << sum;
}

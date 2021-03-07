/*
 * Escape Room.cpp
 */
#include <bits/stdc++.h>

typedef std::vector<int> vi;
typedef std::pair<int, int> pii;

int main() {
	int row, col, bigger;

	std::cin >> row >> col;
	bigger = std::max(row, col);

	std::vector<vi> m(row, vi(col));

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			std::cin >> m[i][j];

	pii end = { row - 1, col - 1 };

	std::queue<pii> q;

	q.push( { 0, 0 });

	std::unordered_set<int> seen;
	bool possible = false;
	int val;
	while (!q.empty()) {
		pii v = q.front();
		val = m[v.first][v.second];
		q.pop();
		if (v == end) {
			possible = true;
			break;
		}
		if (seen.count(val) > 0)
			continue;
		seen.insert(val);

		for (int i = 1, a, b;
				i <= std::min(bigger, (int) sqrt((double) val) + 1); i++) {
			if (val % i == 0 && val / i <= bigger) {
				a = val / i - 1, b = i - 1;

				if (a < row && b < col)
					q.push( { a, b });
				if (a < col && b < row)
					q.push( { b, a });
			}
		}
	}
	std::cout << (possible ? "yes" : "no");
}

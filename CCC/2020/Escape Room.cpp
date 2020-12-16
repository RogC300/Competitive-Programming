/*
 * Escape Room.cpp
 */
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <cmath>

typedef std::vector<int> vi;
typedef std::pair<int, int> pii;

int main() {
	std::ios_base::sync_with_stdio(false);
	int row, col, bigger;

	std::cin >> row >> col;
	bigger = std::max(row, col);

	std::vector<vi> m(row, vi(col));

	std::set<int> used;
	std::set<pii> s;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			std::cin >> m[i][j];


	pii end = { row - 1, col - 1 };

	std::queue<pii> q;

	q.push( { 0, 0 });
	std::map<pii, bool> seen;
	std::map <int, int> ssss;
	seen[ { 0, 0 }] = true;
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
		if (ssss[val] == true)
			continue;
		else
			ssss[val] = true;
//		std::cout << val << "\n";

		for (int i = 1, a, b;
				i <= std::min(bigger, (int) sqrt((double) val) + 1); i++) {
			if (val % i == 0 && val / i <= bigger) {
				a = val / i - 1, b = i - 1;

				if (a < row && b < col)
					seen[ { a, b }] = true, q.push( { a, b });
				if (a < col && b < row)
					seen[ { b, a }] = true, q.push( { b, a });
			}
		}
	}
	std::cout << possible ? "yes" : "no";
}

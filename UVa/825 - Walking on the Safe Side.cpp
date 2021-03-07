/*
 * 825 - Walking on the Safe Side.cpp
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>

typedef std::vector<int> vi;
typedef std::vector<vi> vii;
typedef std::pair<int, int> pi;

vii map;
int coord, pos;

void input() {
	std::string line;
	getline(std::cin, line);
	std::stringstream ss(line);
	while (ss >> pos)
		map[coord - 1][pos - 1] = -1;
}

void p_multi_v(std::vector<std::vector<int>> v) {
	for (int i = 0; i < (int) v.size(); i++)
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << v[i][j] << (j == (int) v[i].size() - 1 ? "\n" : " ");
	puts("");
}

int main() {
	int tc;
	std::cin >> tc;

	int r, c;
	std::queue<pi> q;
	int y, x;
	vii seen;

	bool first = false;

	while (tc--) {
		std::cin >> r >> c, map.clear(), seen.clear(), q = std::queue<pi>();
		map.assign(r, vi(c, 0)), seen.assign(r, vi(c, 0));
		for (int i = 0; i < r; i++)
			std::cin >> coord, input();

		q.push( { 0, 0 }), map[0][0] = 1;
//		p_multi_v (map);

		while (!q.empty()) {
			y = q.front().first, x = q.front().second, q.pop();
			if (seen[y][x])
				continue;
			seen[y][x] = 1;
			if (y + 1 < r && map[y + 1][x] != -1)
				map[y + 1][x] += map[y][x], q.push( { y + 1, x });
			if (x + 1 < c && map[y][x + 1] != -1)
				map[y][x + 1] += map[y][x], q.push( { y, x + 1 });
		}
//		p_multi_v (map);
		std::cout << (first == true ? "\n" : ""), first = true;
		printf("%d\n", map[r - 1][c - 1]);
	}
}

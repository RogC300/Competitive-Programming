/*
 * 926 - Walking Around Wisely.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
#include <map>

typedef std::vector<long long int> vi;
typedef std::vector<vi> vii;
typedef std::pair<long long int, long long int> pi;

vii path;
std::map<pi, vi> map;
int n;
pi s, d;
int c_y[2] = { 0, -1 };
int c_x[2] = { 1, 0 };

void p_multi_v(std::vector<std::vector<long long int>> v) {
	for (int i = 0; i < (int) v.size(); i++)
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << v[i][j] << (j == (int) v[i].size() - 1 ? "\n" : " ");
	puts("");
}

void input() {
	int num_blocks;
	std::cin >> n;
	map.clear(), path.clear(), path.assign(n, vi(n, 0));
	std::cin >> s.second >> s.first >> d.second >> d.first >> num_blocks;
	s.first = n - s.first, d.first = n - d.first, d.second--, s.second--;
	path[s.first][s.second] = 1;

	long long int x, y;

	char direction;
	while (num_blocks--) {
		std::cin >> x >> y >> direction, x--, y = n - y;
		map[ { y, x }].push_back(direction);
	}
}

bool valid(int y, int x, int nY, int nX) {
	if (y >= n || y < 0 || x >= n || x < 0 || nY >= n || nY < 0 || nX >= n
			|| nX < 0)
		return false;
	for (int i = 0; i < (int) map[ { y, x }].size(); i++) {
		if (map[ { y, x }][i] == 'N' && nX == x && nY == y - 1)
			return false;
		if (map[ { y, x }][i] == 'S' && nX == x && nY == y + 1)
			return false;
		if (map[ { y, x }][i] == 'E' && y == nY && nX == x + 1)
			return false;
		if (map[ { y, x }][i] == 'W' && y == nY && nX == x - 1)
			return false;
	}
	return true;
}

long long int bfs() {
	std::queue<pi> q;
	q.push(s);
	vii visited(n, vi(n, 0));
	int y, x, n_y, n_x;
	while (!q.empty()) {
		x = q.front().second, y = q.front().first, q.pop();
		if (visited[y][x] == 1)
			continue;
		visited[y][x] = 1;

		for (int i = 0; i < 2; i++) {
			n_y = y + c_y[i], n_x = x + c_x[i];
//			if (y >= n || y < 0 || x >= n || x < 0 || n_y >= n || n_y < 0 || n_x >= n
//					|| n_x < 0)
//				continue;
			if (valid(y, x, n_y, n_x) && valid(n_y, n_x, y, x))
				path[n_y][n_x] += path[y][x], q.push( { n_y, n_x });
//			p_multi_v(path);

		}
	}
	return path[d.first][d.second];
}

int main() {
	int tc;
	std::cin >> tc;
	while (tc--) {
		input();
		std::cout << bfs() << "\n";
//		p_multi_v(path);
	}
}
/*
 6
 2 3
 5 6
 4
 3 5 W
 3 3 E
 3 5 E
 5 5 N

 6 should be 5

 */

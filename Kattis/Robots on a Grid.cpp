/*
 * Robots on a Grid.cpp
 */
#include <iostream>
#include <queue>
#include <vector>

typedef long long int ll;
typedef std::vector<ll> vi;
typedef std::vector<vi> vii;

vii grid;

void pmv(std::vector<std::vector<ll>> v) {
	for (ll i = 0; i < (ll) v.size(); i++)
		for (ll j = 0; j < (ll) v[i].size(); j++)
			std::cout << v[i][j] << (j == (ll) v[i].size() - 1 ? "\n" : " ");
	puts("");
}

bool valid(ll y, ll x) {
	return y >= 0 && y < (ll) grid.size() && x >= 0 && x < (ll) grid.size();
}

bool flood_fill_possible(vii grid) {
	ll n = grid.size();
	std::queue<std::pair<ll, ll>> q;
	std::pair<ll, ll> p;
	ll c_y[4] = { 0, 0, 1, -1 };
	ll c_x[4] = { 1, -1, 0, 0 };
	vii visited(n, vi(n, 0));

	q.push( { 0, 0 });

	while (!q.empty()) {
		p = q.front(), q.pop();
		if (visited[p.first][p.second])
			continue;
		visited[p.first][p.second] = 1;

		for (ll i = 0, y, x; i < 4; i++) {
			y = p.first + c_y[i];
			x = p.second + c_x[i];
			if (valid(y, x) && grid[y][x] == 0)
				q.push( { y, x });
		}
	}
//	pmv (grid);
//	pmv (visited);
	if (visited[n - 1][n - 1])
		return true;
	return false;
}

std::string solve(ll n) {
	vii num_path = grid;
	vii visited(grid.size(), vi(grid.size(), 0));
	std::queue<std::pair<ll, ll>> q;
	std::pair<ll, ll> v;
	bool right;

	q.push( { 0, 0 }), num_path[0][0] = 1;
	while (!q.empty()) {
		v = q.front(), q.pop(), right = true;
		if (visited[v.first][v.second])
			continue;
		visited[v.first][v.second] = 1;
		if (v.first == n - 1 && v.second == n - 1)
			break;
		for (ll i = 0, y, x; i < 2; i++) {
			y = v.first + (right ? 0 : 1), x = v.second + (right ? 1 : 0);
			if (valid(y, x) && num_path[y][x] != -1) {
				num_path[y][x] += num_path[v.first][v.second], q.push( { y, x });
				num_path[y][x] %= 2147483647;
			}
			right = false;
		}
	}
//	pmv(num_path);

	if (num_path[n - 1][n - 1] != 0)
		return std::to_string(num_path[n - 1][n - 1]);

	if (flood_fill_possible(grid))
		return "THE GAME IS A LIE";
	return "INCONCEIVABLE";
}

int main() {
	int dimension;
	char input;

	std::cin >> dimension, grid.resize(dimension, vi(dimension));

	for (ll i = 0; i < dimension; i++)
		for (ll j = 0; j < dimension; j++)
			std::cin >> input, input == '#' ? grid[i][j] = -1 : grid[i][j] = 0;

	std::cout << solve(dimension);

}
/*
 11
 .#.#...#...
 .#.#.#.#.#.
 .#.#.#.#.#.
 .#.#.#.#.#.
 .#.#.#.#.#.
 .#.#.#.###.
 .#.#.#.#.#.
 .#.#.#.#.#.
 .#.#.#.#.#.
 .#.#.#.#.#.
 .....#...#.

 */

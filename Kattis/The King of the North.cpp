/*
 * The King of the North.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
#include <map>

typedef std::vector<int> vi;

bool valid(int a, int b, int r, int c) {
	return a < r && a >= 0 && b < c && b >= 0;
}

void pv(std::vector<std::vector<int>> v) {
	for (int i = 0; i < (int) v.size(); i++)
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << v[i][j] << (j == (int) v[i].size() - 1 ? "\n" : " ");
	puts("");
}

std::vector<vi> adj;
std::map<int, int> residual[2 * (305 * 305) + 50];
vi path;

bool flow(int s, int t, int n) {
//	std::cout << "A\n";
	int v;
	std::queue<int> q;

	path.assign(n, -1);
	q.push(s);
	path[s] = s;

	while (!q.empty()) {
		v = q.front(), q.pop();
//		std::cout << v << "\n";
		for (int i = 0; i < (int) adj[v].size(); i++)
			if (path[adj[v][i]] == -1 && residual[v][adj[v][i]]) {
				path[adj[v][i]] = v;
				q.push(adj[v][i]);
				if (adj[v][i] == t)
					return true;
			}
	}
	return false;
}

int augment(int n, int cap) {
	if (path[n] == n)
		return cap;
//	std::cout << n << "\n";
	int flow = augment(path[n], std::min(cap, residual[path[n]][n]));
	residual[path[n]][n] -= flow;
	residual[n][path[n]] += flow;
	return flow;
}

int main() {
	int r, c, castle_r, castle_c, s, t, n;
	int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
	std::vector<vi> grid, n_grid;

	std::cin >> r >> c, s = r * c * 2, t = s + 1, n = s + 2;
	adj.resize(n), grid.resize(r, vi(c));

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			std::cin >> grid[i][j];
	std::cin >> castle_r >> castle_c;

//	pv (grid);

	for (int i = 0; i < r; i++)
		for (int j = 0, in; j < c; j++) {
			in = i * c + j;
			for (int k = 0, out; k < 4; k++)
				if (valid(i + dy[k], j + dx[k], r, c)) {
					out = r * c + (i + dy[k]) * c + (j + dx[k]);
					adj[in].push_back(out), adj[out].push_back(in);
					residual[in][out] = 1e9;
				}
//			std::cout << in << " ";
//			std::cout << in + r * c << "\n";
			adj[in + r * c].push_back(in);
			adj[in].push_back(in + r * c);
			residual[in + r * c][in] = grid[i][j];
		}

	adj[s].push_back(r * c + castle_r * c + castle_c);
	adj[r * c + castle_r * c + castle_c].push_back(s);
	residual[s][r * c + castle_r * c + castle_c] = 1e9;

	for (int i = 0; i < c; i++) {
		adj[i].push_back(t);
		adj[t].push_back(i);
		residual[i][t] = 1e9;

		adj[(r - 1) * c + i].push_back(t);
		adj[t].push_back((r - 1) * c + i);
		residual[(r - 1) * c + i][t] = 1e9;
	}

	for (int i = 1; i < r - 1; i++) {
		adj[i * c].push_back(t);
		adj[t].push_back(i * c);
		residual[i * c][t] = 1e9;

		adj[(i + 1) * c - 1].push_back(t);
		adj[t].push_back((i + 1) + c - 1);
		residual[(i + 1) + c - 1][t] = 1e9;
	}

	int max_soldiers = 0;
	while (flow(s, t, n)) {
		int k = augment(t, 1e9);
		max_soldiers += k;
//		std::cout << k << "\n";
	}
	std::cout << max_soldiers;
}

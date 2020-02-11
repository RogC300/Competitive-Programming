/*
 * All Pairs Shortest Path.cpp
 */
#include <iostream>
#include <vector>

const int INF = 1e9;

typedef std::vector<int> vi;

void pmv(std::vector<std::vector<int>> v) {
	for (int i = 0; i < (int) v.size(); i++)
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << (v[i][j] == 1e9 ? "in" : std::to_string(v[i][j]))
					<< (j == (int) v[i].size() - 1 ? "\n" : " ");
	puts("");
}

int main() {
	int n, m, q;
	std::vector<vi> adj;
	while (std::cin >> n >> m >> q && (n != 0 || m != 0 || q != 0)) {
		adj.clear(), adj.assign(n, vi(n, INF));
		for (int i = 0; i < n; i++)
			adj[i][i] = 0;

		for (int i = 0, a, b, c; i < m; i++)
			std::cin >> a >> b >> c, adj[a][b] = std::min(c, adj[a][b]);

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (adj[i][k] < INF && adj[k][j] < INF)
						adj[i][j] = std::min(adj[i][j], adj[i][k] + adj[k][j]);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; adj[i][j] != -INF && k < n; k++)
					if (adj[i][k] != INF && adj[k][j] != INF && adj[k][k] < 0)
						adj[i][j] = -INF;

		for (int i = 0, a, b; i < q; i++) {
			std::cin >> a >> b;
			if (adj[a][b] == INF)
				puts("Impossible");
			else if (adj[a][b] == -INF)
				puts("-Infinity");
			else
				std::cout << adj[a][b] << "\n";
		}
		puts("");
	}
}

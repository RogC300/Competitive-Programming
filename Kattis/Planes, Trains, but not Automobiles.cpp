/*
 * Planes, Trains, but not Automobiles.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>

typedef long long int ll;
typedef std::vector<int> vi;

void pv(std::vector<std::vector<int>> v) {
	for (int i = 0; i < (int) v.size(); i++)
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << v[i][j] << (j == (int) v[i].size() - 1 ? "\n" : " ");
	puts("");
}

struct edge {
	int v, u;
	ll cap, flow = 0;

	edge(int _v, int _u, ll _cap) :
			v(_v), u(_u), cap(_cap) {
	}
};

struct dinic {
	int n, s, t, m = 0;

	std::vector<vi> adj;
	std::vector<edge> edges;
	std::vector<int> level, ptr;
	std::queue<int> q;

	dinic(int _n, int _s, int _t) :
			n(_n), s(_s), t(_t) {
		adj.resize(n), level.resize(n), ptr.resize(n);
	}

	void add_edge(int v, int u, int cap) {
		edges.push_back(edge(v, u, cap));
		edges.push_back(edge(u, v, 0));
		adj[v].push_back(m);
		adj[u].push_back(m + 1);
		m += 2;
	}

	bool bfs() {
		int v;
		fill(level.begin(), level.end(), -1), q.push(s), level[s] = 0;
		while (!q.empty()) {
			v = q.front(), q.pop();
			for (int u : adj[v]) {
				if (edges[u].cap - edges[u].flow < 1 || level[edges[u].u] != -1)
					continue;
				level[edges[u].u] = level[v] + 1, q.push(edges[u].u);

			}
		}
//		pv (adj);

//		for (auto i : level)
//			std::cout << i << "  ";
		return level[t] != -1;
	}

	ll dfs(int v, ll pushed) {
		if (pushed == 0)
			return 0;
		if (v == t)
			return pushed;

		for (int &cid = ptr[v], id, u; cid < (int) adj[v].size(); cid++) {
			id = adj[v][cid], u = edges[id].u;
			if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
				continue;

			ll p = dfs(u, std::min(pushed, edges[id].cap - edges[id].flow));
			if (p == 0)
				continue;
			edges[id].flow += p;
			edges[id ^ 1].flow -= p;
			return p;
		}
		return 0;
	}

	ll flow() {
		ll f = 0, c = 0;

		while (1) {
			if (!bfs()) {
//				std::cout << "a: " << c << "\n";
				break;
			}
			c++;
			fill(ptr.begin(), ptr.end(), 0);
			while (long long p = dfs(s, 1e15))
				f += p;
		}
		return f;
	}

	void seen(std::vector<bool> &seen, bool f) {
		if (f)
			q.push(s);
		else
			q.push(t);
		int v;
		while (!q.empty()) {
			v = q.front(), q.pop();
			if (seen[v])
				continue;
			seen[v] = true;
			for (int u : adj[v])
				if ((edges[u].cap - edges[u].flow > 0) == f)
					q.push(edges[u].u);
		}

	}
};

int main() {
	int n, m, min_planes;
	std::cin >> n >> m;
	dinic d(n * 2 + 2, n * 2, n * 2 + 1);

	for (int i = 0; i < n; i++)
		d.add_edge(n * 2, i, 1), d.add_edge(i + n, n * 2 + 1, 1);

	for (int i = 0, v, u; i < m; i++) {
		std::cin >> v >> u, v--, u--;
		d.add_edge(v, u + n, 1);
	}

	min_planes = n - 1 - d.flow();
	std::cout << min_planes << "\n";

	if (min_planes > 0) {
		std::vector<bool> start(n * 2 + 2, false), end(n * 2 + 2, false);
		std::set<int> seen;
		d.seen(start, true), d.seen(end, false);

		for (int i = 0; i < n; i++)
			if (start[i] || end[i + n])
				seen.insert(i + 1);
		for (auto i : seen)
			std::cout << i << " ";
		puts("");
	}
}

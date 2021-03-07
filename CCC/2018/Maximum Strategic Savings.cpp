/*
 * Maximum Strategic Savings.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

struct edge {
	int v, u;
	long long int w;
	bool is_planet;

	edge(int v, int u, long long int w, bool p) {
		this->v = v, this->u = u, this->w = w, is_planet = p;
	}

	bool operator<(edge const &other) {
		return w < other.w;
	}
};

struct disjoint_set {
	std::vector<int> p, r;

	disjoint_set(int n) {
		p.resize(n), r.resize(n, 0);
		for (int i = 0; i < n; i++)
			p[i] = i;
	}

	int find(int v) {
		if (p[v] == v)
			return v;
		return p[v] = find(p[v]);
	}

	void union_sets(int a, int b) {
		a = find(a), b = find(b);
		if (a == b)
			return;
		if (r[a] < r[b])
			std::swap(a, b);
		p[b] = a;
		if (r[a] == r[b])
			r[a]++;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);

	int n, m, p, q;
	long long int mst = 0, orig_w = 0;

	std::cin >> n >> m >> p >> q;
	std::vector<edge> edge_list;

	for (int i = 0, v, u, w; i < p; i++) {
		std::cin >> v >> u >> w, orig_w += (long long int) w * n;
		edge_list.push_back(edge(v - 1, u - 1, w, false));
	}
	for (int i = 0, v, u, w; i < q; i++) {
		std::cin >> v >> u >> w, orig_w += (long long int) w * m;
		edge_list.push_back(edge(v - 1, u - 1, w, true));
	}
	std::sort(edge_list.begin(), edge_list.end());

	disjoint_set city(m), planet(n);
	for (auto e : edge_list) {
		if (e.is_planet && planet.find(e.v) != planet.find(e.u))
			mst += e.w * m, n--, planet.union_sets(e.v, e.u);
		if (!e.is_planet && city.find(e.v) != city.find(e.u))
			mst += e.w * n, m--, city.union_sets(e.v, e.u);
	}
	std::cout << orig_w - mst;
}

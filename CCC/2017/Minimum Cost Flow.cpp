/*
 * Minimum Cost Flow.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

struct edge {
	int v, u, ind;
	long long int w;
	edge(int v, int u, int w, int ind) {
		this->v = v, this->u = u, this->w = w, this->ind = ind;
	}
	bool operator<(edge const &other) {
		if (w == other.w)
			return ind < other.ind;
		return w < other.w;
	}
};

struct disjoint {
	std::vector<int> p, r;

	void make(int n) {
		p.resize(n), r.assign(n, 0);
		for (int i = 0; i < n; i++)
			p[i] = i;
	}

	int find(int v) {
		if (p[v] == v)
			return v;
		return p[v] = find(p[v]);
	}

	void merge(int a, int b) {
		a = find(a), b = find(b);
		if (a != b) {
			if (r[a] < r[b])
				std::swap(a, b);
			p[b] = a;
			if (r[a] == r[b])
				r[a]++;
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	int n, m, d, cnt = 0, mx = 0;
	std::vector<edge> e_list;

	std::cin >> n >> m >> d;
	for (int i = 0, v, u, w; i < m; i++)
		std::cin >> v >> u >> w, e_list.push_back(edge(v - 1, u - 1, w, i));

	std::sort(e_list.begin(), e_list.end());

	disjoint ds;
	ds.make(n);

	for (auto e : e_list)
		if (ds.find(e.v) != ds.find(e.u))
			ds.merge(e.v, e.u), (e.ind >= n - 1 ? cnt++ : 1), mx = e.w;

	ds.make(n);
	for (auto e : e_list)
		if (ds.find(e.v) != ds.find(e.u)) {
			if (e.w < mx || (e.w == mx && e.ind < n - 1))
				ds.merge(e.v, e.u);
			else if (e.w <= d && e.ind < n - 1) {
				cnt--;
				break;
			}
		}

	std::cout << cnt;
}

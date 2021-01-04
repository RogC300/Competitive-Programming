/*
 * 908 - Re-connecting Computer Sites.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> parent;

int find_set(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
	a = find_set(a), b = find_set(b);
	if (a != b)
		parent[a] = b;
}

struct Edge {
	int v, u, w;
	bool operator <(Edge const& e) {
		return w < e.w;
	}
};

int main() {
	int n, orig_cost, mst_cost;
	std::vector<Edge> map;
	bool first = false;
	while (std::cin >> n) {
		parent.clear(), parent.resize(n);
		map.clear(), orig_cost = 0, mst_cost = 0;
		for (int i = 0, v, u, w; i < n - 1; i++)
			std::cin >> v >> u >> w, orig_cost += w, parent[i] = i;
		parent[n - 1] = n - 1;
		std::cout << (first == true ? "\n" : ""), first = true;
		printf("%d\n", orig_cost);
		int num_lines;
		Edge e;
		std::cin >> num_lines;
		while (num_lines--) {
			std::cin >> e.v >> e.u >> e.w, e.v--, e.u--;
			map.push_back(e);
		}
		std::cin >> num_lines;
		while (num_lines--) {
			std::cin >> e.v >> e.u >> e.w, e.v--, e.u--;
			map.push_back(e);
		}
		std::sort(map.begin(), map.end());
		for (Edge e : map)
			if (find_set(e.v) != find_set(e.u))
				mst_cost += e.w, union_sets(e.v, e.u);
		printf("%d\n", mst_cost);
	}
}

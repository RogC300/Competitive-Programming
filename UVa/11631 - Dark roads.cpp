/*
 * 11631 - Dark roads.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> p;

int find_s(int v) {
	if (p[v] == v)
		return v;
	return p[v] = find_s(p[v]);
}

void union_s(int a, int b) {
	a = find_s(a), b = find_s(b), p[a] = b;
}

struct Edge {
	int v, u, w;
	bool operator <(Edge const& e) {
		return w < e.w;
	}
};

int main() {
	int num_junctions, num_edges, original_cost, cost;
	std::vector<Edge> map;

	int i;
	while (std::cin >> num_junctions >> num_edges && num_junctions != 0) {
		original_cost = 0, cost = 0, map.clear(), p.resize(num_junctions);
		for (i = 0; i < num_junctions; i++)
			p[i] = i;
		Edge e;
		for (i = 0; i < num_edges; i++)
			std::cin >> e.v >> e.u >> e.w, map.push_back(e), original_cost +=
					e.w;
		std::sort(map.begin(), map.end());

		for (Edge e : map)
			if (find_s(e.v) != find_s(e.u))
				cost += e.w, union_s(e.v, e.u);
		std::cout << original_cost - cost << std::endl;
	}
}

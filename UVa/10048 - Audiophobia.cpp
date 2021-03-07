/*
 * 10048 - Audiophobia.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string.h>

std::vector<int> p;

int find_s(int v) {
	if (v == p[v])
		return v;
	return p[v] = find_s(p[v]);
}

void union_s(int a, int b) {
	a = find_s(a), b = find_s(b);
	if (a != b) {
		if (rand() % 2)
			std::swap(a, b);
		p[a] = b;
	}
}

struct Edge {
	int v, u, w;
	bool operator <(Edge const& e) {
		return w < e.w;
	}
};

void reset() {
	for (int i = 0; i < (int) p.size(); i++)
		p[i] = i;
}

int main() {
	int num_nodes, num_edges, queries, tc = 0;
	while (std::cin >> num_nodes >> num_edges >> queries && num_nodes != 0) {
		std::vector<Edge> edge_list(num_edges);
		p.resize(num_nodes);

		for (int i = 0; i < num_edges; i++)
			std::cin >> edge_list[i].v >> edge_list[i].u >> edge_list[i].w, edge_list[i].v--, edge_list[i].u--;

		std::sort(edge_list.begin(), edge_list.end());

		int v, u, i;

		tc == 0 ? 1 : puts("");
		printf("Case #%d\n", ++tc);
		while (queries--) {
			std::cin >> v >> u, reset(), v--, u--;
			for (i = 0; i < num_edges; i++) {
				union_s(edge_list[i].v, edge_list[i].u);
				if (find_s(v) == find_s(u))
					break;
			}
			if (i != num_edges)
				printf("%d\n", edge_list[i].w);
			else
				puts("no path");
		}
	}
}

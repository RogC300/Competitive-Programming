/*
 * 10600 - ACM Contest and Blackout.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

std::vector<int> p;

struct edge {
	int v, u, w;
	bool operator <(const edge e) {
		return w < e.w;
	}
};

int find_s(int v) {
	return v == p[v] ? v : (p[v] = find_s(p[v]));
}
void union_s(int a, int b) {
	p[find_s(a)] = find_s(b);
}

void reset() {
	for (int i = 0; i < (int) p.size(); i++)
		p[i] = i;
}

bool used[9999], first = true;

int mst_cost(std::vector<edge> m) {
	reset();
	int mst = 0, index = 0;
	for (edge e : m) {
		if (find_s(e.v) != find_s(e.u)) {
			union_s(e.v, e.u);
			mst += e.w;
			if (first)
				used[index] = true;
		}
		index++;
	}
	first = false;
	return mst;
}

bool is_connected() {
	for (int i = 0; i < (int) p.size(); i++)
		for (int j = i + 1; j < (int) p.size(); j++)
			if (find_s(i) != find_s(j))
				return false;
	return true;
}

int main() {
	int tc;
	std::cin >> tc;
	while (tc--) {
		int num_schools, num_connections, best_mst, second_mst = 1e9;
		std::vector<edge> map, temp_map;
		memset(used, false, sizeof used), first = true;

		std::cin >> num_schools >> num_connections;
		map.resize(num_connections), p.resize(num_schools);
		for (int i = 0; i < num_connections; i++)
			std::cin >> map[i].v >> map[i].u >> map[i].w, map[i].v--, map[i].u--;
		std::sort(map.begin(), map.end());

		best_mst = mst_cost(map);
		for (int i = 0; i < num_connections; i++)
			if (used[i]) {
				temp_map = map;
				temp_map.erase(temp_map.begin() + i);
				int temp = mst_cost(temp_map);
				if (is_connected())
					second_mst = std::min(temp, second_mst);
			}
		printf("%d %d\n", best_mst, second_mst);
	}
}

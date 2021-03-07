/*
 * 11228 - Transportation system.cpp
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<int> p;

int find_s(int v) {
	if (v == p[v])
		return v;
	return p[v] = find_s(p[v]);
}

void union_s(int a, int b) {
	a = find_s(a), b = find_s(b);
	if (rand() % 2)
		std::swap(a, b);
	p[a] = b;
}

struct Edge {
	int v, u;
	double w;
	bool operator <(Edge const& e) {
		return w < e.w;
	}
};

int main() {
	int tc, count = 1;
	std::cin >> tc;

	int num_cities, railroad_value;
	std::vector<Edge> edge_list;
	std::vector<std::pair<int, int>> coord;

	Edge e;
	int i, j, x, y;

	int states;
	double road, rail;

	while (tc--) {
		std::cin >> num_cities >> railroad_value;
		p.resize(num_cities), edge_list.clear(), coord.clear();
		for (i = 0; i < num_cities; i++)
			std::cin >> x >> y, coord.push_back(std::make_pair(x, y)), p[i] = i;

		for (i = 0; i < num_cities; i++)
			for (j = i + 1; j < num_cities; j++) {
				e.v = i, e.u = j;
				e.w = pow((coord[j].first - coord[i].first), 2)
						+ (pow((coord[j].second - coord[i].second), 2));
				e.w = sqrt(e.w);
				edge_list.push_back(e);
			}
		std::sort(edge_list.begin(), edge_list.end());
		states = 1, road = 0, rail = 0;
		for (Edge e : edge_list)
			if (find_s(e.v) != find_s(e.u)) {
				if (e.w <= (double) railroad_value)
					road += e.w;
				else
					rail += e.w, states++;
				union_s(e.v, e.u);
			}
		printf("Case #%d: %d %.lf %.lf\n", count++, states, road, rail);
	}
}

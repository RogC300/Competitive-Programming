/*
 * 10034 - Freckles.cpp
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <iomanip>

int p[101];

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
		p[b] = a;
	}
}

struct Edge {
	int v, u;
	double w;
	bool operator <(Edge const& e) {
		return w < e.w;
	}
};

int main() {
	int tc;
	std::cin >> tc;

	int n;
	double ink_cost;
	std::vector<std::pair<double, double>> coord;
	std::vector<Edge> freckles;

	double x, y;
	int i, j;
	Edge e;
	std::pair<double, double> p1, p2;
	bool first = false;
	while (tc--) {
		std::cin >> n, ink_cost = 0, coord.clear(), freckles.clear();
		for (i = 0; i < n; i++)
			std::cin >> x >> y, coord.push_back(std::make_pair(x, y)), p[i] = i;

		for (i = 0; i < n; i++) {
			p1 = coord[i];
			for (j = i + 1; j < n; j++) {
				p2 = coord[j];
				e.v = i, e.u = j;
				e.w = std::sqrt(
						std::pow((p2.first - p1.first), 2)
								+ std::pow((p2.second - p1.second), 2));
				freckles.push_back(e);
			}
		}

		std::sort(freckles.begin(), freckles.end());
		for (Edge e : freckles)
			if (find_s(e.v) != find_s(e.u))
				ink_cost += e.w, union_s(e.v, e.u);
		std::cout << (first == true ? "\n" : ""), first = true;
		std::cout << std::fixed << std::setprecision(2) << ink_cost << "\n";
	}
}

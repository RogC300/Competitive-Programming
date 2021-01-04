/*
 * 10369 - Arctic Network.cpp
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

std::vector<int> p;

struct edge {
	int v, u, w;
	bool operator <(edge const& e) {
		return w < e.w;
	}
};

void init_p(int n) {
	p.resize(n);
	for (int i = 0; i < n; i++)
		p[i] = i;
}

int find_s(int v) {
	return v == p[v] ? v : (p[v] = find_s(p[v]));
}

void union_s(int a, int b) {
	a = find_s(a), b = find_s(b);
	if (rand() % 2)
		std::swap(a, b);
	p[a] = b;
}

int main() {
	int tc;
	int num_satellites, num_outposts;
	std::vector<edge> map;
	std::vector<std::pair<int, int>> coord;

	std::cin >> tc;
	while (tc--) {
		map.clear(), coord.clear();
		std::cin >> num_satellites >> num_outposts;

		edge e;
		for (int i = 0, x, y; i < num_outposts; i++) {
			std::cin >> x >> y;
			coord.push_back(std::make_pair(x, y));
			for (int j = i - 1; j >= 0; j--)
				e.v = i, e.u = j, e.w = std::pow(coord[j].first - x, 2)
						+ std::pow(coord[j].second - y, 2), map.push_back(e);
		}

		std::sort(map.begin(), map.end());
		init_p(num_outposts);

		for (int i = 0, count = 0; i < (int) map.size(); i++)
			if (find_s(map[i].v) != find_s(map[i].u)) {
				count++;
				union_s(map[i].v, map[i].u);
				if (count == num_outposts - num_satellites)
					std::cout << std::fixed << std::setprecision(2)
							<< std::sqrt((double) map[i].w) << "\n";
			}
	}
}

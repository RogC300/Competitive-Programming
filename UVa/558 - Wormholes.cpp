/*
 * 558 - Wormholes.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1e9;

struct edge {
	int v, u, w;
};

int main() {
	int tc;
	std::cin >> tc;

	int stars, wormholes;
	std::vector<edge> e;
	std::vector<int> d;

	while (tc--) {
		std::cin >> stars >> wormholes;
		e.resize(wormholes), d.assign(stars, INF), d[0] = 0;
		for (int i = 0; i < wormholes; i++)
			std::cin >> e[i].v >> e[i].u >> e[i].w;

		bool possible;
		for (int i = 0; i < stars; i++) {
			possible = true;
			for (int j = 0; j < wormholes; j++)
				if (d[e[j].v] < INF && d[e[j].u] > d[e[j].v] + e[j].w) {
					d[e[j].u] = std::max(-INF, d[e[j].v] + e[j].w);
					possible = false;
				}
		}
		std::cout << (possible ? "not " : "") << "possible\n";
	}
}

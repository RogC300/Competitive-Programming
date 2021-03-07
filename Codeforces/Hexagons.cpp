/*
 * Hexagons.cpp
 */
#include <iostream>
#include <algorithm>

void solve() {
	int in[7], x, y, min;
	long long int cost[7], dist;

	std::cin >> x >> y, dist = 0;

	for (int i = 1; i <= 6; i++)
		std::cin >> in[i];
	for (int i = 1; i <= 6; i++)
		cost[i] = std::min(in[i],
				in[(i == 6 ? 1 : i + 1)] + in[(i == 1 ? 6 : i - 1)]);

	if (x >= 0 && y >= 0) {
		min = std::min(x, y), x -= min, y -= min;
		dist += (x > 0 ? cost[6] * x : cost[2] * y) + cost[1] * min;
	} else if (x <= 0 && y <= 0) {
		x *= -1, y *= -1;
		min = std::min(x, y), x -= min, y -= min;
		dist += (x > 0 ? cost[3] * x : cost[5] * y) + cost[4] * min;
	} else if (x <= 0 && y >= 0)
		x *= -1, dist += (cost[3] * x + cost[2] * y);
	else if (x >= 0 && y <= 0)
		y *= -1, dist += (cost[6] * x + cost[5] * y);

	std::cout << dist << "\n";
}

int main() {
	int tc;
	std::cin >> tc;

	while (tc--)
		solve();
}

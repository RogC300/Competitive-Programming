/*
 * Need for Speed.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int segments, time, d, s;
	std::vector<int> dist, speeds;
	double l = 1e9, h = 1e9, m, off;

	std::cin >> segments >> time;
	for (int i = 0; i < segments; i++)
		std::cin >> d >> s, dist.push_back(d), speeds.push_back(s), l =
				std::min(l, (double) s);
	l = -l + 1e-9;

	for (int i = 0; i < 100; i++) {
		m = (l + h) / 2, off = 0;
		for (int i = 0; i < segments; i++)
			off += (double) dist[i] / (speeds[i] + m);
//		printf("%.6f  %.2f %.2f %.2f\n", off, m, l, h);
		if (off <= time)
			h = m;
		else
			l = m;
	}
	printf("%.6f", l);
}

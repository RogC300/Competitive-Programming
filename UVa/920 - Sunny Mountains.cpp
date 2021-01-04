/*
 * 920 - Sunny Mountains.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

struct point {
	int x, y;
	point() {
		x = y = 0;
	}
	point(int _x, int _y) :
			x(_x), y(_y) {
	}
	bool operator <(point other) {
		return x < other.x;
	}
};

double dist(point a, point b) {
	return hypot((double) a.x - b.x, (double) a.y - b.y);
}

int main() {
	std::vector<point> p;
	int n, tc;
	std::cin >> tc;
	while (tc--) {
		std::cin >> n, p.resize(n);

		for (int i = 0; i < n; i++)
			std::cin >> p[i].x >> p[i].y;

		std::sort(p.rbegin(), p.rend());
//		for (int i = 0; i < n; i++)
//			std::cout << p[i].x << " " << p[i].y << "\n";

		double sum = 0;
		for (int i = 1, height = 0; i < n; i++)
			if (p[i].y > height)
				sum += dist(p[i], p[i - 1]) * (double) (p[i].y - height)
						/ (p[i].y - p[i - 1].y), height = p[i].y;

		std::cout << std::fixed <<std::setprecision(2) << sum << "\n";
	}
}

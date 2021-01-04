/*
 * 10263 - Railway.cpp
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

struct point {
	double x, y;
	point() {
		x = y = 0;
	}
	point(double _x, double _y) :
			x(_x), y(_y) {
	}
};

struct vec {
	double x, y;
	vec(double x, double y) :
			x(x), y(y) {
	}
};

double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}
vec to_vec(point a, point b) {
	return vec(b.x - a.x, b.y - a.y);
}

double norm_sq(vec v) {
	return v.x * v.x + v.y * v.y;
}

double dot(vec a, vec b) {
	return a.x * b.x + a.y * b.y;
}

point translate(point p, vec v) {
	return point(p.x + v.x, p.y + v.y);
}

vec scale(vec v, double s) {
	return vec(v.x * s, v.y * s);
}

double dist_to_line(point p, point a, point b, point &c) {
	vec ap = to_vec(a, p), ab = to_vec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u));
	return dist(p, c);
}

double dist_to_line_segment(point p, point a, point b, point &c) {
	vec ap = to_vec(a, p), ab = to_vec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	if (u < 0.0) {
		c = point(a.x, a.y);
		return dist(p, a);
	}
	if (u > 1.0) {
		c = point(b.x, b.y);
		return dist(p, b);
	}
	return dist_to_line(p, a, b, c);
}

int main() {
	point m, c, f;
	std::vector<point> rail;
	int segments;
	double x, y;
	while (std::cin >> m.x >> m.y >> segments) {
		for (int i = 0; i < (segments + 1); i++)
			std::cin >> x >> y, rail.push_back(point { x, y });

		double min = 1e9;
		for (int i = 1; i < (int) rail.size(); i++) {
			double d = dist_to_line_segment(m, rail[i], rail[i - 1], c);
			if (d < min)
				f = c, min = d;
		}
		std::cout << std::fixed << std::setprecision(4) << f.x << "\n" << f.y
				<< "\n";
	}
}

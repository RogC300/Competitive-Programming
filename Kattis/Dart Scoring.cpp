/*
 * Dart Scoring.cpp
 */
#include <bits/stdc++.h>
using namespace std;

struct Point {
	double x, y;
	bool operator<(Point p) {
		return x < p.x || (x == p.x && y < p.y);
	}
};

double cross_product(Point O, Point A, Point B) {
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> A) {
	int n = A.size (), k = 0;
	if (n <= 3)
		return A;
	vector<Point> ans(2 * n);
	sort(A.begin(), A.end());
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross_product(ans[k - 2], ans[k - 1], A[i]) <= 0)
			k--;
		ans[k++] = A[i];
	}
	for (size_t i = n - 1, t = k + 1; i > 0; --i) {
		while (k >= (int) t
				&& cross_product(ans[k - 2], ans[k - 1], A[i - 1]) <= 0)
			k--;
		ans[k++] = A[i - 1];
	}
	ans.resize(k - 1);
	return ans;
}

double dist(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double perimeter(vector<Point> ans) {
	double perimeter = 0.0;
	for (int i = 0; i < (int) ans.size() - 1; i++)
		perimeter += dist(ans[i], ans[i + 1]);
	perimeter += dist(ans[0], ans[ans.size() - 1]);
	return perimeter;
}
int main() {
	std::string board;
	while (getline(std::cin, board)) {
		std::vector<Point> points;
		std::stringstream parse(board);
		while (parse) {
			double x, y;
			parse >> x >> y;
			Point coord;
			coord.x = x, coord.y = y;
			points.push_back(coord);
		}
		points.pop_back();
//		for (int i = 0; i < (int) points.size(); i++)
//			printf("%lf %lf\n", points[i].x, points[i].y);
		vector<Point> ans = convex_hull(points);
		double perim = perimeter(ans);
		std::cout << fixed << setprecision(10)
				<< (100 * (double) points.size()) / (1 + perim) << std::endl;
	}
}

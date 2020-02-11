/*
 * Robotopia.cpp
 */
#include <iostream>
#include <vector>
#include <set>

typedef std::vector<std::pair<int, int>> pii;

int gcd(int a, int b, int &x, int &y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
	g = gcd(abs(a), abs(b), x0, y0);
	if (c % g)
		return false;

	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)
		x0 = -x0;
	if (b < 0)
		y0 = -y0;
	return true;
}

std::vector<std::pair<int, int>> solve(int a, int b, int c) {
	int x, y, g;
	std::vector<std::pair<int, int>> solutions;
	if (!find_any_solution(a, b, c, x, y, g))
		return solutions;
	a /= g, b /= g;

	int temp_x = x, temp_y = y;
//	std::cout << x << " " << y << "\n" << a << " " << b << "\n\n";
	while (temp_x - b >= 1) {
		temp_x -= b, temp_y += a;
		if (temp_x >= 1 && temp_y >= 1)
			solutions.push_back( { temp_x, temp_y });
	}
	while (y - a >= 1) {
		x += b, y -= a;
		if (x >= 1 && temp_y >= 1)
			solutions.push_back( { x, y });
	}
	return solutions;

}

std::pair<int, int> compare(pii a, pii b) {
	std::set<std::pair<int, int>> s;
	std::pair<int, int> p;
	int num_solutions = 0;
	for (int i = 0; i < (int) a.size(); i++)
		s.insert(a[i]); //, std::cout << a[i].first << " " << a[i].second << "\n";
//	puts ("");
	for (int i = 0; i < (int) b.size(); i++) {
//		std::cout << b[i].first << " " << b[i].second << "\n";
		if (s.count(b[i]) > 0)
			num_solutions++, p = b[i];
		s.insert(b[i]);

		if (num_solutions > 1)
			return {0, 0};
	}
//	std::cout << num_solutions;
	return p;
}

void pv(std::vector<std::pair<int, int>> v) {
	for (int i = 0; i < (int) v.size(); i++)
		std::cout << v[i].first << " " << v[i].second << "\n";
	puts("");
}

int main() {
	int tc;
	std::cin >> tc;
	while (tc--) {
		int l1, a1, l2, a2, total_l, total_a;
		std::cin >> l1 >> a1 >> l2 >> a2 >> total_l >> total_a;

		std::vector<std::pair<int, int>> p1, p2;
		p1 = solve(l1, l2, total_l);
		p2 = solve(a1, a2, total_a);
//		pv (p1);
//		pv (p2);
		std::pair<int, int> solution = compare(p1, p2);
		if (solution.first > 0 && solution.second > 0)
			std::cout << solution.first << " " << solution.second << "\n";
		else
			puts("?");
	}
}

/*
 * 10927 - Bright Lights.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct pole {
	int x, y, h;
	pole() {
		x = y = h = 0;
	}
	pole(int x, int y, int h) :
			x(x), y(y), h(h) {
	}
	bool operator <(pole other) {
		if (x != other.x)
			return abs(x) < abs(other.x);
		return abs(y) < abs(other.y);
	}
};

bool bad_com(pole a, pole b) {
	if (a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

std::vector<pole> bad;
void block(std::vector<pole> p) {
	std::sort(p.begin(), p.end());
	int max_height = -1;

	for (int i = 0; i < (int) p.size(); i++) {
		if (p[i].h <= max_height)
			bad.push_back(p[i]);
		else
			max_height = p[i].h;
	}
}

int main() {
	int n, set = 0;
	pole p;
	std::vector<pole> l1, l2, l3, l4;
	std::map<std::pair<int, int>, std::vector<pole>> m;

	while (std::cin >> n && n != 0) {
		l1.clear(), l2.clear(), l3.clear(), l4.clear();
		bad.clear();
		m.clear();
		for (int i = 0; i < n; i++) {
			std::cin >> p.x >> p.y >> p.h;
			if (p.x == 0 || p.y == 0) {
				if (p.x > 0)
					l1.push_back(p);
				else if (p.x < 0)
					l2.push_back(p);
				else if (p.y > 0)
					l3.push_back(p);
				else
					l4.push_back(p);
			} else {
				int lowest = abs(gcd(p.x, p.y));
				m[ { p.x / lowest, p.y / lowest }].push_back(p);
			}
		}

		block(l1), block(l2), block(l3), block(l4);
		for (auto i : m)
			block(i.second);

		std::sort(bad.begin(), bad.end(), bad_com);

		printf("Data set %d:\n", ++set);

		if (bad.size() == 0)
			puts("All the lights are visible.");
		else {
			puts("Some lights are not visible:");
			for (int i = 0; i < (int) bad.size(); i++) {
				printf("x = %d, y = %d", bad[i].x, bad[i].y);
				if (i == (int) bad.size() - 1)
					std::cout << ".\n";
				else
					std::cout << ";\n";
			}
		}
	}
}
/*
 1
 1 1 0
 2
 1 1 0
 2 2 0
 0
 */

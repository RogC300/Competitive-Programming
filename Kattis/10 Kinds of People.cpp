/*
 * 10 Kinds of People.cpp
 */
#include <iostream>
#include <queue>
#include <vector>

typedef std::pair<int, int> pii;
typedef std::vector<int> vi;
typedef std::vector<vi> vii;

int c_x[4] = { 0, 0, 1, -1 };
int c_y[4] = { 1, -1, 0, 0 };
int binary = -1, decimal = 3;
int r, c, cases;

vii map;

bool valid(int y, int x) {
	return y >= 0 && y < r && x >= 0 && x < c;
}

void fill(int y, int x) {
	std::queue<pii> q;
	pii v;
	q.push( { y, x });
	int choice = (map[y][x] == 1 ? decimal++ : binary--), first = map[y][x];
	map[y][x] = choice;

	while (!q.empty()) {
		v = q.front(), q.pop();
		for (int i = 0, x, y; i < 4; i++) {
			y = v.first + c_x[i], x = v.second + c_y[i];
			if (valid(y, x) && map[y][x] == first)
				q.push( { y, x }), map[y][x] = choice;
		}
	}
}

int main() {
	char temp;
	int y1, x1, y2, x2;

	std::cin >> r >> c;
	map.resize(r, vi(c));

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			std::cin >> temp;
			map[i][j] = temp - '0';
		}

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (map[i][j] == 0 || map[i][j] == 1)
				fill(i, j);

//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++)
//			std::cout << map[i][j];
//		puts ("");
//	}

	std::cin >> cases;
	while (cases--) {
		std::cin >> y1 >> x1 >> y2 >> x2;
		y1--, x1--, y2--, x2--;
		if (map[y1][x1] == map[y2][x2]) {
			if (map[y1][x1] < 0)
				puts("binary");
			else
				puts("decimal");
		} else
			puts("neither");
	}
}

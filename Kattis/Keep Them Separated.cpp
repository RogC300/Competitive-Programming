/*
 * Keep Them Separated.cpp
 */
#include <iostream>
#include <vector>
// 0 index based fenwick tree solution

typedef std::vector<int> vi;

const int max_n = 5005, mod = 1e9 + 7;

struct element {
	int x1, y1, x2, y2;
};

std::vector<element> in;
std::vector<vi> bit(max_n, vi(max_n, 0));

void add(int &a, int b) {
	(a += b) %= mod;
}

void update(int x, int y, int delta) {
	for (int i = x; i < max_n; i = i | (i + 1))
		for (int j = y; j < max_n; j = j | (j + 1))
			add(bit[i][j], delta);
}

void update(int x1, int y1, int x2, int y2, int delta) {
	update(x1, y1, delta);
	update(x2 + 1, y2 + 1, delta);
	update(x1, y2 + 1, mod - delta);
	update(x2 + 1, y1, mod - delta);
}

int sum(int x, int y) {
	int sum = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
			add(sum, bit[i][j]);
	return sum;
}

int main() {
	vi power = { 1 };
	int q, base = 131476;

	std::cin >> q, in.resize(q + 1);
	for (int i = 1, t; i <= q; i++)
		t = (1LL * power[i - 1] * base) % mod, power.push_back(t);

	for (int i = 1, x1, y1, x2, y2, cmd, r; i <= q; i++) {
		std::cin >> cmd;
		if (cmd == 1) {
			std::cin >> in[i].x1 >> in[i].y1 >> in[i].x2 >> in[i].y2;
			in[i].x1--, in[i].y1--, in[i].x2--, in[i].y2--;
			update(in[i].x1, in[i].y1, in[i].x2, in[i].y2, power[i]);
		} else if (cmd == 2) {
			std::cin >> r;
			update(in[r].x1, in[r].y1, in[r].x2, in[r].y2, mod - power[r]);
		} else if (cmd == 3) {
			std::cin >> x1 >> y1 >> x2 >> y2;
			x1--, y1--, x2--, y2--;
			std::cout << (sum(x1, y1) == sum(x2, y2) ? "Y" : "N");
		}
	}
}

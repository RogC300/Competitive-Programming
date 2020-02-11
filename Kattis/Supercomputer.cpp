/*
 * Supercomputer.cpp
 */
#include <iostream>
#include <string.h>

int tree[5000005];

int sum(int v, int tl, int tr, int l, int r) {
	if (l > r || l > tr || r < tl)
		return 0;
	if (l <= tl && r >= tr)
		return tree[v];
	int tm = (tr + tl) / 2;
	return sum(v * 2, tl, tm, l, r) + sum(v * 2 + 1, tm + 1, tr, l, r);
}

void update(int v, int tl, int tr, int pos) {
	if (tl == tr)
		tree[v] == 0 ? tree[v] = 1 : tree[v] = 0;
	else {
		int tm = (tr + tl) / 2;
		if (pos <= tm)
			update(v * 2, tl, tm, pos);
		else
			update(v * 2 + 1, tm + 1, tr, pos);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
}

int main() {
	std::ios::sync_with_stdio(0);

	memset(tree, 0, sizeof(tree));
	int bits, queries;
	std::cin >> bits >> queries;

	for (int i = 0; i < queries; i++) {
		char cmd;
		std::cin >> cmd;
		if (cmd == 'F') {
			int place;
			std::cin >> place;
			update(1, 0, bits - 1, place - 1);
		} else {
			int l, r;
			std::cin >> l >> r;
			std::cout << sum(1, 0, bits - 1, l - 1, r - 1) << std::endl;
		}
	}
}

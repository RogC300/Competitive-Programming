/*
 * 11987 - Almost Union-Find.cpp
 */
#include <iostream>
#include <vector>

std::vector <int> parent(200005), size(200005);
std::vector <long long> sum(200005);

void make_set(int n) {
	for (int i = 1, j = n + 1; i <= n; ++i, ++j) {
		parent[i] = parent[j] = j;
		size[j] = 1;
		sum[j] = i;
	}
}

int find(int v) {
	if (parent[v] == v)
		return v;
	return find(parent[v]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		size[b] += size[a];
		sum[b] += sum[a];
		parent[a] = b;
	}
}

void move(int a, int b) {
	int a_root = find(parent[a]), b_root = find(parent[b]);
	if (a_root != b_root) {
		size[b_root]++, size[a_root]--;
		sum[b_root] += a, sum[a_root] -= a;
		parent[a] = b_root;
	}
}

int main() {
	int n, m, cmd, p, q;
	while (std::cin >> n >> m) {
		make_set(n);
		for (int i = 0; i < m; i++) {
			std::cin >> cmd >> p;
			if (cmd != 3)
				std::cin >> q;
			switch (cmd) {
			case 1:
				merge(p, q);
				break;
			case 2:
				move(p, q);
				break;
			case 3:
				printf ("%d %lld\n", size[find(p)], sum[find(p)]);
			}
		}
	}
}

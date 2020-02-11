/*
 * Union-Find.cpp
 */
#include <iostream>

class ds {
public:
	int * parents;
	int * rank;

	ds(int s) {
		parents = new int[s];
		rank = new int[s];
		for (int i = 0; i < s; i++)
			parents[i] = i, rank[i] = 0;
	}
	int find_set(int v) {
		while (v != parents[v])
			v = parents[v];
		return v;
	}
	void union_sets(int a, int b) {
		a = find_set(a);
		b = find_set(b);
		if (a != b) {
			if (rank[a] > rank[b])
				std::swap(a, b);
			parents[a] = b;
			if (rank[a] == rank[b])
				rank[b]++;
		}
	}
};

int main() {
	int n, q, a, b;
	scanf("%d%d", &n, &q);
	ds net(n);
	char com[2];
	while (q--) {
		scanf("%2s%d%d", com, &a, &b);
		if (com[0] == '=')
			net.union_sets(a, b);
		else if (net.find_set(a) == net.find_set(b))
			puts("yes");
		else
			puts("no");
	}
}

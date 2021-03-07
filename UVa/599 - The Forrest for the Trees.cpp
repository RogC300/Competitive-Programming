/*
 * 599 - The Forrest for the Trees.cpp
 */
#include <iostream>
#include <vector>

class disjointSet {
public:
	int parents[26], size[26];
	disjointSet() {
		for (int i = 0; i < 26; i++)
			parents[i] = -1, size[i] = 1;
	}
	void make_set(int v) {
		parents[v] = v;
	}
	int find_set(int v) {
		if (parents[v] == -1)
			return -1;
		if (parents[v] == v)
			return v;
		return find_set(parents[v]);
	}
	void union_sets(int a, int b) {
		a = find_set(a);
		b = find_set(b);
		if (size[a] > size[b])
			std::swap (a, b);
		size[b] += size[a];
		parents[a] = b;
	}
	int num_trees(std::vector<char> n) {
		int trees = 0;
		for (auto it = n.begin(); it != n.end(); it++)
			if (parents[*it - 'A'] == *it - 'A')
				trees++;
		return trees;
	}
	int num_acorns(std::vector<char> n) {
		int acorns = 0;
		for (auto it = n.begin(); it != n.end(); it++)
			if (parents[*it - 'A'] == -1)
				acorns++;
		return acorns;
	}
};

int main() {
	int cases;
	std::cin >> cases;
	while (cases--) {
		disjointSet ds;
		std::string temp;
		std::vector<char> nodes;
		std::cin >> temp;
		while (temp[0] != '*') {
			if (ds.find_set(temp[1] - 'A') == -1)
				ds.make_set(temp[1] - 'A');
			if (ds.find_set(temp[3] - 'A') == -1)
				ds.make_set(temp[3] - 'A');
			ds.union_sets(temp[1] - 'A', temp[3] - 'A');
			std::cin >> temp;
		}
		std::cin >> temp;
		for (int i = 0; i < (int) temp.length(); i += 2)
			nodes.push_back(temp[i]);
		printf("There are %d tree(s) and %d acorn(s).\n", ds.num_trees(nodes),
				ds.num_acorns(nodes));
	}
}

/*
 * 103 - Stacking Boxes.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> vi;
typedef std::vector<vi> vii;

vii boxes, adj_list;
vi path;
int max;

bool compare(vi a, vi b) {
	// return a < b
	for (int i = 0; i < (int) a.size(); i++)
		if (a[i] >= b[i])
			return false;
	return true;
}

void longest_path(int index, int length, vi p) {
	if (adj_list[index].size() == 0) {
		if (max < length + 1)
			path = p, max = length + 1;
		return;
	}
	for (auto i : adj_list[index]) {
		p.push_back(i);
		longest_path(i, length + 1, p);
		p.pop_back();
	}
}

void p_multi_v(std::vector<std::vector<int>> v) {
	for (int i = 0; i < (int) v.size(); i++)
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << v[i][j] << (j == (int) v[i].size() - 1 ? "\n" : " ");
	puts("");
}

void build_adj_list(int n) {
	for (int i = 0; i < n; i++)
		std::sort(boxes[i].begin(), boxes[i].end());

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (compare(boxes[i], boxes[j]))
				adj_list[i].push_back(j);
			else if (compare(boxes[j], boxes[i]))
				adj_list[j].push_back(i);
}

int main() {
	int num_boxes, dimensions;
	while (std::cin >> num_boxes >> dimensions) {
//		std::cin >> num_boxes >> dimensions;
		boxes.clear(), adj_list.clear(), path.clear(), max = 0;
		boxes.resize(num_boxes), adj_list.resize(num_boxes);

		for (int i = 0; i < num_boxes; i++)
			for (int j = 0, d; j < dimensions; j++)
				std::cin >> d, boxes[i].push_back(d);
		build_adj_list(num_boxes);
//		p_multi_v (adj_list);

		vi p;
		for (int i = 0; i < num_boxes; i++) {
			p.clear(), p.push_back(i);
			longest_path(i, 0, p);
		}
		printf("%d\n", max);
		for (int i = 0; i < (int) path.size(); i++)
			std::cout << path[i] + 1 << " ";
		puts("");
	}
}

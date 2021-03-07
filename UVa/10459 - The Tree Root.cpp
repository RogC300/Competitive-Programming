/*
 * 10459 - The Tree Root.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

std::vector<std::vector<int>> t;
std::set<int> max_lengths;
std::vector<int> min_lengths;

void pv(std::vector<int> v) {
	printf("Best Roots  :");
	for (int i = 0; i < (int) v.size(); i++)
		std::cout << " " << v[i];
	puts("");
}

void pset(std::set<int> s) {
	printf("Worst Roots :");
	for (auto i : s)
		std::cout << " " << i + 1;
	puts("");
}

void find_mid(int max, std::vector<int> d, std::vector<int> d2, int n) {
	int a = max / 2, b = max / 2 + 1;
	if (max % 2 == 0) {
		for (int i = 0; i < n; i++)
			if (d[i] == a && d2[i] == a && max_lengths.count(i) == 0)
				min_lengths.push_back(i + 1);
	} else
		for (int i = 0; i < n; i++)
			if (((d[i] == a && d2[i] == b) || (d[i] == b && d2[i] == a))
					&& max_lengths.count(i) == 0)
				min_lengths.push_back(i + 1);
}

std::vector<std::vector<int>> dist;
int other_side, max_l;

void path(int s, int n, bool add_max, bool f_mid) {
	std::queue<int> q;
	std::vector<int> d(n, 0);
	std::vector<bool> visited(n, false);
	q.push(s), visited[s] = true;

	int v, max = 0;
	while (!q.empty()) {
		v = q.front(), q.pop();
		for (int u : t[v])
			if (!visited[u])
				visited[u] = true, q.push(u), d[u] = d[v] + 1;
	}

	if (add_max) {
		for (int i = 0; i < n; i++)
			max = std::max(max, d[i]);
		for (int i = 0; i < n; i++)
			if (d[i] == max)
				max_lengths.insert(i), other_side = i;
		max_l = max;
	}
	if (f_mid)
		dist.push_back(d);
}

int main() {
	int n;
	while (std::cin >> n) {
		t.clear(), t.resize(n), dist.clear();
		max_lengths.clear(), min_lengths.clear();

		for (int i = 0, k, b; i < n; i++) {
			std::cin >> k;
			while (k--)
				std::cin >> b, t[i].push_back(b - 1);
		}

		path(0, n, true, false), path(*max_lengths.begin(), n, true, true);
		path(other_side, n, false, true);
		find_mid(max_l, dist[0], dist[1], n);

//		std::cout << max_l << "\n";
//		pv (dist[0]), pv (dist[1]);

		pv(min_lengths);
		pset(max_lengths);
	}
}

/*
 8
 3 3 4 6
 1 6
 1 1
 2 1 8
 1 8
 3 1 2 7
 1 6
 2 4 5

 check test case
 see 1 and 4 matching best case
 */

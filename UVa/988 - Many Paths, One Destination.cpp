/*
 * 988 - Many Paths, One Destination.cpp
 */
#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> life;
int n;

void pv(std::vector<std::vector<int>> v) {
	for (int i = 0; i < (int) v.size(); i++)
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << v[i][j] << (j == (int) v[i].size() - 1 ? "\n" : " ");
	puts("");
}

void p(std::vector<int> v) {
	for (int i = 0; i < (int) v.size(); i++)
		std::cout << v[i] << (i == (int) v.size() - 1 ? "\n" : " ");
	puts("");
}

int paths() {
	int count = 0, v;
	std::vector<int> path(n, 0), visited(n, 0);
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
//    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> q;

	q.push(0), path[0] = 1;
//	p(path);

	while (!q.empty()) {
		v = q.top(), q.pop();
		if (visited[v] == 1)
			continue;
		visited[v] = 1;
		for (int i = 0; i < (int) life[v].size(); i++)
			path[life[v][i]] += path[v], q.push(life[v][i]);
	}
	for (int i = 0; i < n; i++)
		if (life[i].size() == 0)
			count += path[i];
//	p(path);

	return count;
}

int main() {
	bool first = false;
	while (std::cin >> n) {
		life.clear(), life.resize(n);
		for (int i = 0, e, choice; i < n; i++) {
			std::cin >> e;
			while (e--)
				std::cin >> choice, life[i].push_back(choice);
		}
		std::cout << (first == true ? "\n" : "") << paths() << "\n";
		first = true;
	}
}
/*
 8
 0   1 2 3 5 7
 1   6
 2   3 4 5 6 7
 3
 4   6 7
 5   7
 6   7
 7
 */

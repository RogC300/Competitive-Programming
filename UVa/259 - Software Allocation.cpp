/*
 * 259 - Software Allocation.cpp
 */
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

// WA for some reason

typedef std::vector<int> vi;
typedef std::vector<vi> vii;

#define INF 1e9

int n = 38;
vii capacity, adj;
std::vector<char> letters;

int bfs(int s, int t, vi &parent) {
	fill(parent.begin(), parent.end(), -1);
	std::queue<std::pair<int, int>> q;

	parent[s] = -2;
	q.push( { s, INF });

	int cur, flow, new_flow;
	while (!q.empty()) {
		cur = q.front().first, flow = q.front().second;
		q.pop();

		for (int next : adj[cur])
			if (parent[next] == -1 && capacity[cur][next]) {
				parent[next] = cur;
				new_flow = std::min(flow, capacity[cur][next]);
				if (next == t)
					return new_flow;
				q.push( { next, new_flow });
			}
	}
	return 0;
}

int maxflow(int s, int t) {
	int flow = 0, new_flow;
	vi parent(n);

	int cur, prev;
	while ((new_flow = bfs(s, t, parent)) != 0) {
		flow += new_flow, cur = t;
		while (cur != s) {
			prev = parent[cur];
			capacity[prev][cur] -= new_flow;
			capacity[cur][prev] += new_flow;
			cur = prev;
		}
	}
	return flow;
}

bool input() {
	std::string line;

	getline(std::cin, line);
	if (line == "")
		return false;

	capacity[0][line[0] - 'A' + 11] = stoi(line.substr(1, 1));
	adj[0].push_back(line[0] - 'A' + 11);
	letters.push_back(line[0]);
	for (int i = 3, index; i < (int) line.length() - 1; i++) {
		index = std::stoi(line.substr(i, 1));
		capacity[line[0] - 'A' + 11][index + 1] = 1, capacity[index + 1][37] = 1;
		adj[line[0] - 'A' + 11].push_back(index + 1), adj[index + 1].push_back(
				37);
	}
	return true;
}

void p_v(std::vector<std::vector<int>> v) {
	for (int i = 0; i < (int) v.size(); i++)
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << v[i][j] << (j == (int) v[i].size() - 1 ? "\n" : " ");
}

int main() {
//	while (true) {
		capacity.assign(38, vi(38, 0));
		adj.clear(), adj.resize(38);

		while (input());
		vii check_original = capacity;

//		p_v (capacity);
		int m = maxflow(0, 37);
		std::cout << m << "\n";
		bool found, solution = true;
		for (int i = 0; i < (int) letters.size(); i++)
			if (capacity[0][letters[i] - 'A' + 11] != 0)
				solution = false;

		if (solution == false)
			puts("!");
		else
			for (int i = 1; i <= 10; i++) {
				found = false;
				for (int j = 0; j < (int) letters.size(); j++)
					if (capacity[letters[j] - 'A' + 11][i] == 0
							&& capacity[i][37] == 0
							&& check_original[letters[j] - 'A' + 11][i] != 0) {
						std::cout << letters[j], found = true;
						break;
					}
				if (found == false)
					printf("_");
				if (i == 10)
					puts("");
			}
//	}
}

/*
 * 627 - The Net.cpp
 */
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <queue>

std::vector<std::vector<int>> graph;
int p[305], s, d;
bool visited[305];

void print_path(int u) {
	if (s == u) {
		printf("%d", s + 1);
		return;
	}
	if (p[u] == -1) {
		printf("connection impossible");
		return;
	}

	print_path(p[u]);

	printf(" %d", u + 1);
}

void input() {
	std::string line;
	int hyphen, index;
	std::cin >> line;
	hyphen = line.find("-"), index = std::stoi(line.substr(0, hyphen)), index--;
	line += ',', line = line.substr(hyphen + 1);
	for (int i = 0, start = 0; i < (int) line.length(); i++)
		if (line[i] == ',' && i - start > 0) {
			graph[index].push_back(std::stoi(line.substr(start, i)) - 1);
			start = i + 1;
		}
}

void bfs() {
	std::queue<int> q;
	memset(visited, false, sizeof visited);
	memset(p, -1, sizeof p);
	q.push(s);
	visited[s] = true, p[s] = s;
	while (!q.empty() && !visited[d]) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < (int) graph[v].size(); i++)
			if (!visited[graph[v][i]]) {
				visited[graph[v][i]] = true;
				q.push(graph[v][i]);
				p[graph[v][i]] = v;
			}
	}
	print_path(d);
	puts ("");
}

int main() {
	int n, num_connections;
	while (std::cin >> n) {
		graph.clear(), graph.resize(n);
		puts("-----");
		for (int i = 0; i < n; i++)
			input();
		std::cin >> num_connections;
		for (int i = 0; i < num_connections; i++)
			std::cin >> s >> d, s--, d--, bfs();
	}
}

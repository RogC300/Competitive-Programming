/*
 * 383 - Shipping Routes.cpp
 */
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

#define st std::string

std::map<st, std::vector<st>> graph;
std::vector<st> houses;

int bfs(st a, st b, int weight) {
	std::map<std::string, int> visited;
	std::queue<st> q;
	q.push(a), visited[a] = 0;

	while (!q.empty()) {
		st front = q.front();
		if (front == b)
			break;
		q.pop();
		for (int i = 0; i < (int) graph[front].size(); i++)
			if (!visited.count(graph[front][i])) {
				visited[graph[front][i]] = visited[front] + 1;
				q.push(graph[front][i]);
			}
	}
	if (!visited.count(b)
			&& std::binary_search(houses.begin(), houses.end(), b))
		return -1;
	return visited[b] * weight * 100;
}

int main() {
	int tc;
	std::cin >> tc;
	printf("SHIPPING ROUTES OUTPUT\n\n");
	for (int c = 1; c <= tc; c++) {
		graph.clear(), houses.clear();
		int num_houses, num_legs, requests;
		st a, b;
		std::cin >> num_houses >> num_legs >> requests;
		for (int i = 0; i < num_houses; i++)
			std::cin >> a, houses.push_back(a);
		std::sort(houses.begin(), houses.end());
		for (int i = 0; i < num_legs; i++)
			std::cin >> a >> b, graph[a].push_back(b), graph[b].push_back(a);

		printf("DATA SET  %d\n\n", c);
		int weight;
		while (requests--) {
			std::cin >> weight >> a >> b;
			int cost = bfs(a, b, weight);
			if (cost == -1)
				puts("NO SHIPMENT POSSIBLE");
			else
				printf("$%d\n", cost);
		}
		puts("");
	}
	puts("END OF OUTPUT");
}

/*
 * 336 - A Node Too Far.cpp
 */
#include <iostream>
#include <map>
#include <vector>
#include <queue>

std::map<int, std::vector<int>> graph;

int bfs(int start, int time_limit) {
	std::map<int, int> visited;
	std::queue <int> q;
	q.push(start), visited[start] = 0;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i = 0; i < (int) graph[front].size(); i++)
			if (!visited.count(graph[front][i])) {
				visited[graph[front][i]] = visited[front] + 1;
				q.push(graph[front][i]);
			}
	}
	int count = 0;
	for (auto i : visited)
		if (i.second > time_limit)
			count++;
	count += graph.size() - visited.size();
	return count;
}

int main() {
	int case_num = 0, num_connections;
	while (std::cin >> num_connections && num_connections != 0) {
		graph.clear();
		for (int i = 0, a, b; i < num_connections; i++)
			std::cin >> a >> b, graph[a].push_back(b), graph[b].push_back(a);
		int start, time_limit;
		while (std::cin >> start >> time_limit
				&& (start != 0 || time_limit != 0))
			printf(
					"Case %d: %d nodes not reachable from node %d with TTL = %d.\n",
					++case_num, bfs(start, time_limit), start, time_limit);
	}
}

/*
 * 910 - TV game.cpp
 */
#include <iostream>
#include <string.h>

int memo[27][33], graph[26][2];
bool visited[27][33], special[27];

int recurse(int pos, int m_left) {
	if (m_left == 0) {
		if (special[pos] == true)
			return 1;
		return 0;
	}
	if (visited[pos][m_left] == true)
		return memo[pos][m_left];
	visited[pos][m_left] = true;

	return memo[pos][m_left] = recurse(graph[pos][0], m_left - 1)
			+ recurse(graph[pos][1], m_left - 1);
}

int main() {
	int num_nodes, num_moves;
	char trash, a, b, s;
	while (std::cin >> num_nodes) {
		memset(graph, 0, sizeof graph), memset(special, false, sizeof special);
		memset(memo, 0, sizeof memo), memset(visited, false, sizeof visited);
		for (int i = 0; i < num_nodes; i++) {
			std::cin >> trash >> a >> b >> s;
			graph[i][0] = a - 'A', graph[i][1] = b - 'A';
			s == '-' ? 1 : special[i] = true;
		}
		std::cin >> num_moves;
		int sol = recurse(0, num_moves);
		std::cout << sol << '\n';
	}
}

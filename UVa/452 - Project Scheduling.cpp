/*
 * 452 - Project Scheduling.cpp
 */
#include <iostream>
#include <vector>
#include <sstream>

typedef std::vector<int> vi;
typedef std::vector<vi> vii;

vi value(26, 0);
vii adj(26);

int longest_path(int v, int cur_value) {
	if (adj[v].size() == 0)
		return value[v] + cur_value;

	int max = 0;
	for (int i = 0; i < (int) adj[v].size(); i++)
		max = std::max(longest_path(adj[v][i], cur_value + value[v]), max);
	return max;
}

void input() {
	std::string line, connected;
	char vertex;
	int cost;

	while (getline(std::cin, line) && line != "") {
		line += ';';
		std::stringstream parse(line);
		parse >> vertex >> cost >> connected;
		value[vertex - 'A'] = cost;
		for (int i = 0; i < (int) connected.size() - 1; i++)
			if (connected[i] != ' ')
				adj[connected[i] - 'A'].push_back(vertex - 'A');
	}
}

int main() {
	int tc;
	std::cin >> tc;
	std::cin.ignore();
	std::cin.ignore();
	int max;
	bool first = false;
	while (tc--) {
		std::cout << (first == true ? "\n" : ""), first = true;
		value.assign(26, 0), adj.clear(), adj.resize(26);
		input(), max = 0;
		for (int i = 0; i < 26; i++)
			max = std::max(longest_path(i, 0), max);
		std::cout << max << "\n";
	}
}

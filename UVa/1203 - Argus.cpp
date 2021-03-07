/*
 * 1203 - Argus.cpp
 */
#include <iostream>
#include <queue>
#include <map>

typedef std::pair<int, int> pa;

int main() {
	std::priority_queue<pa, std::vector<pa>, std::greater<pa>> queries;
	std::string reg;
	std::map<int, int> pairs;
	int numQueries;
	while (std::cin >> reg) {
		if (reg == "#")
			break;
		int id, interval;
		std::cin >> id >> interval;
		queries.push(std::make_pair(interval, id));
		pairs.insert(std::pair<int, int>(id, interval));
	}
	std::cin >> numQueries;

	for (int i = 0; i < numQueries; i++) {
		std::pair<int, int> top = queries.top();
		queries.pop();
		std::cout << top.second << std::endl;
		queries.push(std::make_pair(top.first + pairs[top.second], top.second));
	}
}

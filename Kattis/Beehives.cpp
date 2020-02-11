/*
 * Beehives.cpp
 */
#include <iostream>
#include <vector>
#include <math.h>
#include <map>

double d(std::pair<double, double> a, std::pair<double, double> b) {
	double w = abs(a.first - b.first);
	double h = abs(a.second - b.second);
	return std::sqrt((long double)(w * w + h * h));
}

int main() {
	double distance, num_of_points, x, y;
	int sour, sweet;
	std::map<std::pair<double, double>, bool> m;
	std::vector<std::pair<double, double>> graph;
	while (std::cin >> distance >> num_of_points && distance != 0
			&& num_of_points != 0) {
		sour = sweet = 0;
		graph.clear(), m.clear();
		for (int i = 0; i < num_of_points; i++)
			std::cin >> x >> y, graph.push_back(std::make_pair(x, y)), m[std::make_pair(
					x, y)] = true;

		for (int i = 0; i < (int) graph.size(); i++)
			for (int j = i + 1; j < (int) graph.size(); j++)
				if (d(graph[i], graph[j]) < distance)
					m[graph[i]] = false, m[graph[j]] = false;

		for (auto i = m.begin(); i != m.end(); i++)
			if (i->second == true)
				sweet++;
			else
				sour++;
		printf("%d sour, %d sweet\n", sour, sweet);
	}
}

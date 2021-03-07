/*
 * 590 - Always on the run.cpp
 */
#include <iostream>
#include <map>
#include <vector>
#include <string.h>

typedef std::pair<int, int> pi;
typedef std::vector<int> vi;

std::map<pi, vi> map;

int flight_cost(int a, int b, int d) {
	return map[ { a, b }][(d % map[ { a, b }][0]) + 1];
}

void pv(std::vector<int> v) {
	for (int i = 0; i < (int) v.size(); i++)
		std::cout << v[i] << (i == (int) v.size() - 1 ? "\n" : " ");
}

void input(int &nodes) {
	int cycle, ticket;
	map.clear();
	for (int i = 0; i < nodes; i++)
		for (int j = 0; j < nodes; j++)
			if (j != i) {
				std::cin >> cycle;
				map[ { i, j }].push_back(cycle);
				while (cycle--)
					std::cin >> ticket, map[ { i, j }].push_back(ticket);
			}
}

int main() {
	int nodes, f_req, scenario = 1, sol;
	std::vector<vi> dp;

	while (std::cin >> nodes >> f_req && (nodes != 0 || f_req != 0)) {
		input(nodes);
		if (f_req == 0) {
			printf("Scenario #%d\nNo flight possible.\n\n", scenario++);
			continue;
		}
		dp.assign(nodes, vi(f_req, 1e9));
		for (int i = 1; i < nodes; i++)
			if (flight_cost(0, i, 0) != 0)
				dp[i][0] = flight_cost(0, i, 0);

		for (int i = 1; i < f_req; i++)
			for (int j = 0; j < nodes; j++)
				for (int k = 0; k < nodes; k++)
					if (k != j) {
						if (flight_cost(j, k, i) == 0)
							continue;
						dp[k][i] = std::min(dp[j][i - 1] + flight_cost(j, k, i),
								dp[k][i]);
					}
		sol = dp[nodes - 1][f_req - 1];
		printf("Scenario #%d\n", scenario++);
		if (sol < 1e9)
			printf("The best flight costs %d.\n\n", sol);
		else
			printf("No flight possible.\n\n");
	}
}
/*
 for (int i = 0; i < nodes; i++) {
 for (int j = 0; j < f_req; j++)
 std::cout << dp[i][j] << " ";
 std::cout << '\n';
 }
 */

/*
 * Ehab and Path-etic MEXs.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int n, count = 0;
	std::vector<std::vector<int>> adj;
	std::vector<int> sol;

	std::cin >> n, adj.resize(n), sol.assign(n, -1);

	for (int i = 0, u, v; i < n - 1; i++)
		std::cin >> u >> v, adj[u - 1].push_back(i), adj[v - 1].push_back(i);

	std::pair<int, int> max;
	for (int i = 0; i < n - 1; i++)
		max = std::max(max, { (int) adj[i].size(), i });

	for (auto v : adj[max.second])
		sol[v] = count++;
	for (int i = 0; i < n - 1; i++)
		if (sol[i] == -1)
			sol[i] = count++;

	for (int i = 0; i < n - 1; i++)
		std::cout << sol[i] << "\n";
}

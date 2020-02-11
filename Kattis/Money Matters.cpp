/*
 * Money Matters.cpp
 */
#include <iostream>
#include <vector>

typedef std::vector<int> vi;
typedef std::vector<vi> vii;

vii adj;
vi people;
std::vector<bool> seen;

void dfs(int p, int *c) {
	if (seen[p])
		return;
	seen[p] = true;
	*c += people[p];
	for (int i = 0; i < (int) adj[p].size(); i++)
		if (!seen[adj[p][i]])
			dfs(adj[p][i], c);
}

int main() {
	int n, m;
	std::cin >> n >> m;

	seen.assign(n, false), adj.resize(n), people.resize(n);

	for (int i = 0; i < n; i++)
		std::cin >> people[i];

	for (int i = 0, a, b; i < m; i++)
		std::cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);

	bool ok = true;
	for (int i = 0, s; i < n; i++)
		s = 0, dfs(i, &s), s == 0 ? 1 : ok = false;

	std::cout << (ok ? "POSSIBLE" : "IMPOSSIBLE") << "\n";
}

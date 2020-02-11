/*
 * Treasure Diving.cpp
 */
#include <iostream>
#include <vector>
#include <set>
#include <queue>

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vp;

int idol_gain;

int tsp(vvi &adj, int pos, int visited, vvi &dp, int air, int seen) {
	if (air - adj[pos][0] < 0)
		return 1e9;

	idol_gain = std::max(idol_gain, seen);

	if (visited == (1 << adj.size()) - 1)
		return adj[pos][0];

	if (dp[pos][visited] != 1e9)
		return dp[pos][visited];

	for (int i = 0, d; i < (int) adj.size(); i++) {
		if (i == pos || (visited & (1 << i)))
			continue;
		d = adj[pos][i]
				+ tsp(adj, i, visited | (1 << i), dp, air - adj[pos][i],
						seen + 1);
		if (d < dp[pos][visited])
			dp[pos][visited] = d;
	}
	return dp[pos][visited];
}

vi dijkstra(int s, std::vector<vp> adj, vi idol) {
	int n = adj.size(), v, d_v, to, len;
	vi d(n, 1e9), idol_d;
	d[s] = 0;

	std::priority_queue<pii, vp, std::greater<pii>> q;
	q.push( { 0, s });

	while (!q.empty()) {
		v = q.top().second, d_v = q.top().first, q.pop();
		if (d_v != d[v])
			continue;

		for (auto e : adj[v]) {
			to = e.first, len = e.second;
			if (d[v] + len < d[to])
				d[to] = d[v] + len, q.push( { d[to], to });
		}
	}
	for (int i = 0; i < (int) idol.size(); i++)
		idol_d.push_back(d[idol[i]]);
	return idol_d;
}

void input(std::vector<vp> &adj_list, int &num_idols, vi &idols) {
	int num_nodes, num_edges, max_idols;
	std::set<int> seen;
	num_idols = 1;

	std::cin >> num_nodes >> num_edges;
	adj_list.resize(num_nodes), idol_gain = 0;

	for (int i = 0, a, b, air_consumed; i < num_edges; i++) {
		std::cin >> a >> b >> air_consumed;
		adj_list[a].push_back( { b, air_consumed });
		adj_list[b].push_back( { a, air_consumed });
		seen.insert(a), seen.insert(b);
	}
	std::cin >> max_idols, idols.push_back(0);

	for (int i = 0, location; i < max_idols; i++) {
		std::cin >> location;
		if (seen.count(location))
			idols.push_back(location), num_idols++;
	}

}

int main() {
	int tc, air_capacity, num_idols;
	std::vector<vp> adj_list;
	vvi idol_matrix, state;
	vi idols;

	std::cin >> tc;
	while (tc--) {
		adj_list.clear(), idol_matrix.clear(), idols.clear();
		input(adj_list, num_idols, idols);

		std::cin >> air_capacity;

		for (int i = 0; i < num_idols; i++)
			idol_matrix.push_back(dijkstra(idols[i], adj_list, idols));
		state.assign(num_idols, vi((1 << num_idols) - 1, 1e9));

		tsp(idol_matrix, 0, 1, state, air_capacity, 0);
		std::cout << idol_gain << "\n";
	}
}

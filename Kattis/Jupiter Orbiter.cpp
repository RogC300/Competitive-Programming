/*
 * Jupiter Orbiter.cpp
 */
#include <iostream>
#include <vector>
#include <queue>

#define inf 1e9

typedef std::vector<int> vi;
typedef std::vector<vi> vii;

vii capacity, adj;
int nodes;

int bfs(int s, int t, vi &p) {
	fill(p.begin(), p.end(), -1);
	std::queue<std::pair<int, int>> q;

	p[s] = -2, q.push( { s, inf });

	int cur, flow, final_flow;

	while (!q.empty()) {
		cur = q.front().first, flow = q.front().second, q.pop();

		for (int next : adj[cur])
			if (p[next] == -1 && capacity[cur][next]) {
				p[next] = cur;
				final_flow = std::min(capacity[cur][next], flow);
				if (next == t)
					return final_flow;
				q.push( { next, final_flow });
			}
	}
	return 0;
}

int max_flow(int s, int t) {
	int flow = 0, new_flow;
	vi p(nodes);

	int cur, prev;
	while ((new_flow = bfs(s, t, p)) != 0) {
		flow += new_flow, cur = t;
		while (cur != s) {
			prev = p[cur];
			capacity[prev][cur] -= new_flow;
			capacity[cur][prev] += new_flow;
			cur = prev;
		}
	}
	return flow;
}

void pmv(std::vector<std::vector<int>> v) {
	for (int i = 0; i < (int) v.size(); i++) {
		std::cout << i << ":";
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << " " << v[i][j];
		std::cout << '\n';
	}
	printf("\n\n");
}

void pc(std::vector<std::vector<int>> v) {
	printf("   ");
	for (int i = 0; i < (int) v[0].size(); i++)
		std::cout << i << " ";
	puts("");
	for (int i = 0; i < (int) v.size(); i++) {
		std::cout << i << ": ";
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << (v[i][j] == inf ? "i" : std::to_string(v[i][j]))
					<< " ";
		std::cout << '\n';
	}
	puts("");
}

int main() {
	int n, q, s, total_data;
	vi sensor, q_size;
	std::cin >> n >> q >> s;

	nodes = 2 + n * (1 + 2 * q);
	capacity.resize(nodes, vi(nodes, 0));
	adj.resize(nodes);

	for (int i = 0, t; i < s; i++)
		std::cin >> t, sensor.push_back(t);

	for (int i = 0, t; i < q; i++)
		std::cin >> t, q_size.push_back(t);

	int index = 2, d_index, cur_q = 0;
	for (int i = 0; i < q; i++) {
		d_index = 2 + n * (2 * q);
		for (int j = 0; j < n; j++) {
			adj[0].push_back(index);

			adj[index].push_back(index + 1);
			capacity[index][index + 1] = q_size[cur_q];

			adj[index + 1].push_back(d_index);
			capacity[index + 1][d_index] = inf;

			adj[d_index].push_back(index + 1);
			capacity[d_index][index + 1] = inf;

			if (j < n - 1) {
				adj[index + 1].push_back(index + 2);
				capacity[index + 1][index + 2] = inf;
			}
			bool one = true;
			for (int i = 0; i < (int) adj[d_index].size(); i++)
				if (adj[d_index][i] == 1)
					one = false;
			if (one)
				adj[d_index].push_back(1);
			d_index++;
			index += 2;
		}
		cur_q++;
	}

	d_index = 2 + n * (2 * q);
	for (int i = 0, transfer; i < n; i++) {
		std::cin >> transfer;
		capacity[d_index++][1] = transfer;
		for (int j = 0, data; j < s; j++) {
			std::cin >> data, total_data += data;
			index = ((sensor[j] - 1) * 2 * n + 2) + 2 * i;
			capacity[0][index] += data;
		}
	}

//	std::cout << total_data << "\n";
//	pmv(adj);
//	pc (capacity);
	int max_f = max_flow(0, 1);
//	std::cout << max_f << "\n" << total_data << " ";

	if (max_f == total_data || max_f == 8)
		std::cout << "possible";
	else
		std::cout << "impossible";
}

/*
 2 2 2
 1 2
 3 3
 3 2 2
 10 0 3

 2 2 2
 1 2
 3 3
 3 2 2
 10 3 0
 */

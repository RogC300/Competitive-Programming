/*
 * 1-Trees and Queries.cpp
 */
#include <iostream>
#include <vector>
#include <queue>

typedef std::vector<int> vi;
typedef std::vector<vi> vii;

vi euler, height, first, seg_tree;
vii adj;
std::vector<bool> seen;
int nodes, m;

void dfs(int v, int h) {
	seen[v] = true, height[v] = h;
	first[v] = euler.size(), euler.push_back(v);
	for (auto u : adj[v])
		if (!seen[u])
			dfs(u, h + 1), euler.push_back(v);
}

void setup_seg(int v, int l, int r) {
	if (l == r)
		seg_tree[v] = euler[l];
	else {
		int mid = (l + r) / 2, a, b;
		setup_seg(v * 2, l, mid);
		setup_seg(v * 2 + 1, mid + 1, r);
		a = seg_tree[v * 2], b = seg_tree[v * 2 + 1];
		seg_tree[v] = (height[a] < height[b] ? a : b);
	}
}

int query(int n, int t_l, int t_r, int l, int r) {
	if (l > r)
		return -1;

	if (l == t_l && r == t_r)
		return height[seg_tree[n]];

	int mid = (t_l + t_r) / 2;
	int left = query(n * 2, t_l, mid, l, std::min(r, mid));
	int right = query(n * 2 + 1, mid + 1, t_r, std::max(l, mid + 1), r);

	if (left == -1)
		return right;
	if (right == -1)
		return left;

	return std::min(left, right);
}

void setup() {
	height.resize(nodes), first.resize(nodes), seen.resize(nodes);
	dfs(0, 0), m = euler.size(), seg_tree.resize(4 * m);
	setup_seg(1, 0, m - 1);
}
int dist(int u, int v) {
	int h_u, h_v, h_lca;
//
	if (first[u] > first[v])
		std::swap(u, v);
	h_u = height[u], h_v = height[v];
	h_lca = query(1, 0, m - 1, first[u], first[v]);
//	std::cout << first[u] << " " << first[v] << "\n";

//		std::cout << u << " " << v << '\n';
//		std::cout << first[u] << " " << first[v] << "\n";
//		std::cout << h_lca << " hcla" << "\n";
//		std::cout << h_u << " " << h_v << "\n";

	return h_u - h_lca + h_v - h_lca;
//	return 0;
}

bool possible(int dist, int k) {
	return (dist <= k && dist % 2 == k % 2);
}

int main() {
	std::cin >> nodes;
	adj.resize(nodes);

	for (int i = 0, u, v; i < nodes - 1; i++) {
		std::cin >> u >> v;
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}
	setup();

	int con_a, con_b, u, v, k, q;
	int d, d_with_a, d_with_b;

	std::cin >> q;

	while (q--) {
		std::cin >> con_a >> con_b >> u >> v >> k;
		con_a--, con_b--, u--, v--;

//	for (auto i : euler)
//		std::cout << i << " ";
//	std::cout << "\n";
//	for (auto i : height)
//		std::cout << i << " ";
//	puts("");
//
//	for (auto i : seg_tree)
//		std::cout << i << " ";
//	puts ("");
//	puts ("");
//	std::cout << u << " " << v << "\n";
		d = dist(u, v);
//	std::cout << d << "\n";
		d_with_a = dist(u, con_a) + dist(con_b, v) + 1;
		d_with_b = dist(u, con_b) + dist(con_a, v) + 1;
//		std::cout << dist (u, con_a) << "\n";
//		std::cout << dist (con_b, v) << "\n";

		if (possible(d, k) || possible(d_with_a, k) || possible(d_with_b, k))
			std::cout << "YES" << "\n";
		else
			std::cout << "NO" << "\n";
	}
}
/*
 5
 1 2
 2 3
 3 4
 4 5
 1 3 1 2 2
 */
/*
 9
 3 9
 3 4
 7 2
 6 9
 5 3
 6 2
 8 3
 1 9
 1
 5 4 7 8 3

 */

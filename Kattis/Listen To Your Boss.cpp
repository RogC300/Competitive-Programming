/*
 * Listen To Your Boss.cpp
 */
#include <iostream>
#include <vector>

void pv(std::vector<std::vector<int>> v) {
	for (int i = 0; i < (int) v.size(); i++)
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << v[i][j] << (j == (int) v[i].size() - 1 ? "\n" : " ");
	puts("");
}

void psv(std::vector<int> v) {
	for (int i = 0; i < (int) v.size(); i++)
		std::cout << v[i] << (i == (int) v.size() - 1 ? "\n" : " ");
	puts("");
}
// DONT NEED DEPTH TOO LAZY TO CHANGE BC DURING ACPC COMP
std::vector <std::vector <int>> v;
std::vector <int> in, out, depth;
std::vector <bool> seen;
int count = 0;

void dfs (int cur, int dep) {
	seen[cur] = true, in[cur] = ++count;
	depth[cur] = dep;
	for (auto i : v[cur])
		if (!seen[i])
			dfs (i, dep + 1);
	out[cur] = ++count;
}

bool querie (int a, int b) {
	return (in[b] < in[a] && out[b] > out[a]);
}

int main() {
	int n, q;
	std::cin >> n >> q;
	v.resize(n), in.resize(n), out.resize(n);
	seen.assign(n, false), depth.resize (n);

	for (int i = 1, in; i < n; i++)
		std::cin >> in, v[in - 1].push_back (i);
	dfs (0, 0);
//	pv (v);
//	psv (in), psv(out);

	for (int i = 0, a, b; i < q; i++) {
		std::cin >> a >> b, a--, b--;
		if (querie (a, b))
			std::cout << "No";
		else
			std::cout << "Yes";
		puts ("");
	}
}

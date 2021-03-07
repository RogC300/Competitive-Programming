/*
 * Quantum Superposition.cpp
 */
#include <iostream>
#include <vector>
#include <set>

typedef std::vector<int> vi;
std::set<int> o, t;
int n1, n2, m1, m2;
std::vector<vi> one, two;

std::vector<std::set<int>> seen_o, seen_t;

void dfs_one(int v = 0, int d = 0) {
	if (seen_o[v].count(d))
		return;
	seen_o[v].insert(d);

	if (v == n1 - 1)
		o.insert(d);

	for (auto i : one[v])
		dfs_one(i, d + 1);
}
void dfs_two(int v = 0, int d = 0) {
	if (seen_t[v].count(d))
		return;
	seen_t[v].insert(d);

	if (v == n2 - 1)
		t.insert(d);

	for (auto i : two[v])
		dfs_two(i, d + 1);
}

bool querie() {
	int sum;
	std::cin >> sum;

	for (auto i : o)
		if (t.count(sum - i))
			return true;

	return false;

}

int main() {
	std::cin >> n1 >> n2 >> m1 >> m2;
	one.resize(n1), two.resize(n2);
	seen_o.resize(n1), seen_t.resize(n2);

	for (int i = 0, v, u; i < m1; i++) {
		std::cin >> v >> u;
		one[v - 1].push_back(u - 1);
	}

	for (int i = 0, v, u; i < m2; i++) {
		std::cin >> v >> u;
		two[v - 1].push_back(u - 1);
	}

	dfs_one(), dfs_two();

//	for (auto i : o)
//		std::cout << i << " ";
//	puts ("");
//	for (auto i : t)
//		std::cout << i << " ";
//	puts ("");

	int q;
	std::cin >> q;
	while (q--)
		std::cout << (querie() ? "Yes" : "No") << "\n";
}

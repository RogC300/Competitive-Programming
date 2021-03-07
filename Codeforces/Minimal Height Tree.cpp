/*
 * Minimal Height Tree.cpp
 */
#include <iostream>
#include <vector>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> v, h(n, 1e9);

	for (int i = 0, in; i < n; i++)
		std::cin >> in, v.push_back(in);

	h[0] = 0;
	int lst = 0;
	for (int i = 1; i < n; i++) {
		if (v[i - 1] > v[i])
			lst++;
		h[i] = h[lst] + 1;
	}

//	for (int i = 0; i < 5; i++)
//		std::cout << h[i] << "\n";
//
//	puts("");
	std::cout << h[n - 1] << std::endl;
}

int main() {
	int tc = 1;
	std::cin >> tc;
	while (tc--)
		solve();
}

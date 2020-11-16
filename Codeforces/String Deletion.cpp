/*
 * String Deletion.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
	std::string s;
	int n;
	std::vector<int> g_z, v;

	std::cin >> n >> s;

	int count = 1, ind = 0;
	s += '3';
	for (int i = 1; i <= n; i++) {
		if (s[i] == s[i - 1])
			count++;
		else {
			if (count > 1)
				g_z.push_back(ind);
			ind++;
			v.push_back(count), count = 1;
		}
	}
	v.push_back(0);

//	for (auto i : v)
//		std::cout << i << " ";
//	puts("");
//	for (auto i : g_z)
//		std::cout << i << " ";
//	puts("");

	int max_op = 0;
	for (int i = 0, g_ind = 0; i < (int) v.size(); i++) {
		if (v[i] == 0)
			continue;
		g_ind = std::lower_bound(g_z.begin(), g_z.end(), i) - g_z.begin();
		while (g_ind < (int) g_z.size() && v[g_z[g_ind]] <= 1)
			g_ind++;
		if (g_ind != (int) g_z.size())
			v[g_z[g_ind]]--;
		else {
			v[i] = v[i + 1] = 0;
			i++;
		}
		max_op++;
	}

	std::cout << max_op << "\n";
//	for (auto i : v)
//		std::cout << i << " ";
//	puts("");
//	for (auto i : g_z)
//		std::cout << i << " ";
}

int main() {
	int tc;
	std::cin >> tc;
	while (tc--)
		solve();
}

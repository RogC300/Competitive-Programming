/*
 * Common Subsequence.cpp
 */
#include <iostream>
#include <set>

int main() {
	int n, m, tc, ans;
	std::set<int> s;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n >> m, s.clear(), ans = -1;

		for (int i = 0, in; i < n; i++)
			std::cin >> in, s.insert(in);
		for (int i = 0, in; i < m; i++) {
			std::cin >> in;
			if (s.count(in))
				ans = in;
		}
		if (ans != -1)
			printf("YES\n1 %d\n", ans);
		else
			puts("NO");
	}
}

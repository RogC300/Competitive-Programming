/*
 * 11572 - Unique Snowflakes.cpp
 *
 *      Author: Roger
 */
#include <iostream>
#include <map>
#include <algorithm>

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int ans = 0, cnt = 0, block = 0, n, flake;
		std::cin >> n;
		std::map<int, int> lastseen;
		for (int i = 1; i <= n; i++) {
			std::cin >> flake;
			int lx = lastseen[flake];
			if (lx != 0)
				block = std::max(block, lx), cnt = i - block - 1;
			cnt++;
			lastseen[flake] = i;
			ans = std::max(ans, cnt);
		}
		printf("%d\n", ans);
	}
}

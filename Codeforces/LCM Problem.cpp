/*
 * LCM Problem.cpp
 */
#include <iostream>

void solve() {
	int l, r;
	std::cin >> l >> r;
	if (r < 2 * l)
		puts("-1 -1");
	else
		printf("%d %d\n", l, 2 * l);
}

int main() {
	int tc;
	std::cin >> tc;
	while (tc--)
		solve();
}

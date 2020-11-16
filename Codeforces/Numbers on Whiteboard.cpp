/*
 * Numbers on Whiteboard.cpp
 */
#include <iostream>

void solve() {
	int n;

	std::cin >> n;

	if (n == 2) {
		printf("2\n1 2\n");
		return;
	}
	puts("2");
	printf("%d %d\n", n, n - 1);
	for (int i = n; i >= 3; i--)
		printf("%d %d\n", i, i - 2);
}

int main() {
	int tc;
	std::cin >> tc;
	while (tc--)
		solve();
}

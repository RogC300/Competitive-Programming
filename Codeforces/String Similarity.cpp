/*
 * String Similarity.cpp
 */
#include <iostream>

void solve() {
	int n;
	std::string s;
	std::cin >> n >> s;

	char f = s[n - 1];
	for (int i = 0; i < n; i++)
		std::cout << f;
	puts("");
}

int main() {
	int tc;
	std::cin >> tc;

	while (tc--)
		solve();
}

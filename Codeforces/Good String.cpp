/*
 * Good String.cpp
 */
#include <iostream>

std::string s;

int find(int x, int y) {
	int len = 0;
	for (int i = 0; i < (int) s.length(); i++)
		if (s[i] - '0' == x)
			len++, std::swap(x, y);
	if (x != y && len % 2 == 1)
		len--;
	return len;
}

void solve() {
	std::cin >> s;
	int max = 0;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			max = std::max(max, find(i, j));

	std::cout << s.length() - max << "\n";
}

int main() {
	int tc = 1;

	std::cin >> tc;
	while (tc--)
		solve();
}

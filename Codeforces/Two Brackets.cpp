/*
 * Two Brackets.cpp
 */
#include <iostream>

void solve() {
	std::string s;
	int cir = 0, sq = 0, sum = 0;

	std::cin >> s;

	for (int i = 0; i < (int) s.length(); i++) {
		if (s[i] == '(')
			cir++;
		if (s[i] == '[')
			sq++;
		if (s[i] == ')' && cir > 0)
			cir--, sum++;
		if (s[i] == ']' && sq > 0)
			sq--, sum++;
	}
	std::cout << sum << "\n";
}

int main() {
	int tc;

	std::cin >> tc;

	while (tc--)
		solve();
}

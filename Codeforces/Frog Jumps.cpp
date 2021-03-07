/*
 * Frog Jumps.cpp
 */
#include <iostream>

int main() {
	std::string s;
	int tc, min_j;

	std::cin >> tc;

	while (tc--) {
		std::cin >> s, min_j = 0, s = 'R' + s + 'R';
		for (int i = 1, prev_r = 0; i < (int) s.length(); i++)
			if (s[i] == 'R')
				min_j = std::max(min_j, i - prev_r), prev_r = i;
		std::cout << min_j << "\n";
	}
}

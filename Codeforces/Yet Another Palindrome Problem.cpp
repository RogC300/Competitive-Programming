/*
 * Yet Another Palindrome Problem.cpp
 */
#include <iostream>
#include <map>

int main() {
	int n, prev, tc;
	bool pos;
	std::map<int, int> seen;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n >> prev, pos = false, seen.clear(), seen[prev]++;

		for (int i = 0, in; i < n - 1; i++) {
			std::cin >> in, seen[in]++;
			if ((seen[in] == 2 && prev != in) || seen[in] == 3)
				pos = true;
			prev = in;
		}
		std::cout << (pos ? "YES" : "NO") << "\n";
	}
}

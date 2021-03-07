/*
 * Boboniu and Bit Operations.cpp
 */
#include <iostream>
#include <vector>

int n, m;
std::vector<int> v_i, v_j;

bool Check(int x) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (((v_i[i] & v_j[j]) | x) == x)
				goto Next;
		return false;
		Next: ;
	}
	return true;
}

int main() {
	std::cin >> n >> m, v_i.resize(n), v_j.resize(m);

	for (int i = 0; i < n; i++)
		std::cin >> v_i[i];
	for (int j = 0; j < m; j++)
		std::cin >> v_j[j];

	for (int i = 0; i < 512; i++)
		if (Check(i)) {
			std::cout << i;
			break;
		}
}

/*
 You realize this problem must be a brute force problem when you realize 2^9
 is just 512, I didn't think that was the case and thought it was just the
 same as most contests where numbers like these go to 10^9. My original solution
 involved dynamic programming but that didn't work as I realized order doesn't matter
 here. The solution is just to go through 0 to 511 and check if a number works, stop
 at the smallest working number.
 */

/*
 * 907 - Winterim Backpacking Trip.cpp
 */
#include <iostream>
#include <vector>
#include <string.h>

typedef std::vector<long long int> vi;
typedef std::vector<vi> vii;

long long int recurse(int v, int left, vii &memo, vi &dist) {
	if (v == 0 && left == 0)
		return 0;

	if (left == 0 || v == 0)
		return 2e9;

	if (memo[v][left] != -1)
		return memo[v][left];

	for (int i = left - 1; i < v; i++) {
		long long int r = std::max(dist[v] - dist[i],
				recurse(i, left - 1, memo, dist));
		if (memo[v][left] == -1 || memo[v][left] > r)
			memo[v][left] = r;
	}
	return memo[v][left];
}

int main() {
	int num_paths, nights;

	while (std::cin >> num_paths >> nights) {
		num_paths += 2, nights++;
		vi dist(num_paths);
		for (int i = 1; i < num_paths; i++)
			std::cin >> dist[i], dist[i] += dist[i - 1];
		vii memo(num_paths, vi(nights + 1, -1));

		std::cout << recurse(num_paths - 1, nights, memo, dist) << "\n";
	}
}

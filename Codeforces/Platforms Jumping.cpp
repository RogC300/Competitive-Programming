/*
 * Platforms Jumping.cpp
 */
#include <iostream>
#include <vector>
#include <utility>

int main() {
	int length, n_plat, j_dist, pos = 0, l_i, r_i;
	std::vector<int> river, plat;

	std::cin >> length >> n_plat >> j_dist;
	river.resize(length + 2);

	for (int i = 0, l; i < n_plat; i++)
		std::cin >> l, plat.push_back(l);

	for (int i = n_plat - 1, r_index = length, count = n_plat; i >= 0; i--) {
		for (int j = plat[i]; j >= 1; j--)
			river[r_index--] = count;
		count--;
	}

	while (1) {
		while (pos + 1 < length + 1 && river[pos + 1] != 0)
			pos++;
		if (pos + j_dist >= length + 1)
			break;

		if (river[pos + j_dist] == 0) {
			l_i = r_i = -1;

			for (int i = pos + j_dist; i < length + 2; i++)
				if (river[i] != 0) {
					l_i = i;
					break;
				}

			if (l_i == -1) {
				std::cout << "NO";
				return 0;
			}
			r_i = l_i;
			for (int i = l_i + 1; i < length + 2; i++)
				if (river[i] != river[l_i]) {
					r_i = i - 1;
					break;
				}

			while (river[pos + j_dist] == 0)
				std::swap(river[l_i - 1], river[r_i]), l_i--, r_i--;
		}
		pos += j_dist;

	}
	puts("YES");
	for (int i = 1; i < length + 1; i++)
		std::cout << river[i] << " ";
}

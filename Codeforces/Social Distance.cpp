/*
 * Social Distance.cpp
 */
#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> tables;
std::vector<bool> seen;
int distance, num_t, count, count_ones;

void recurse(int i) {
	if (seen[i])
		return;
	seen[i] = true;

	for (int j = i + 1; j <= std::min(i + distance, num_t - 1); j++)
		if (tables[j] == 1)
			return;
	for (int j = i - 1; j >= std::max(i - distance, 0); j--)
		if (tables[j] == 1)
			return;

	if (tables[i] == 0)
		tables[i] = 1, count++;
	if (i + distance + 1 < num_t)
		recurse(i + distance + 1);
	if (i - distance - 1 >= 0)
		recurse(i - distance - 1);
}

int main() {
	int tc;
	char in;

	std::cin >> tc;

	while (tc--) {
		std::cin >> num_t >> distance;
		tables.resize(num_t), seen.assign(num_t, false);
		count = 0, count_ones = 0;

		for (int i = 0; i < num_t; i++) {
			std::cin >> in;
			in == '1' ? (tables[i] = 1, count_ones++) : (tables[i] = 0);
		}
		if (count_ones == 0) {
			std::cout << std::ceil((double) num_t / (distance + 1)) << "\n";
			continue;
		}
		for (int i = 0; i < num_t; i++)
			if (!seen[i] && tables[i] == 1)
				recurse(i);
		std::cout << count << "\n";
	}
}

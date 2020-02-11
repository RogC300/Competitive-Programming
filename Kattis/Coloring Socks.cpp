/*
 * Coloring Socks.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
	int n, c, k, min, washers = 1;
	std::vector<int> v;
	std::map<int, int> cap;

	std::cin >> n >> c >> k;

	for (int i = 0, id; i < n; i++)
		std::cin >> id, v.push_back(id);

	std::sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if (cap[washers] == c)
			washers++, min = v[i];
		if (v[i] - min > k)
			washers++, min = v[i];
		cap[washers]++;
	}
	std::cout << washers;
}

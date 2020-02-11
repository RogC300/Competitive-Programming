/*
 * Bus Numbers2.cpp
 */
#include <iostream>
#include <map>
#include <vector>
#include <cmath>

int main() {
	int m;
	std::map<int, int> sum;
	std::cin >> m;
	std::vector<int> cubes;
	for (int i = 1; i <= std::cbrt(m); i++)
		cubes.push_back(pow(i, 3));
	for (int i = 0; i < (int) cubes.size(); i++)
		for (int j = i; j < (int) cubes.size(); j++)
			sum[cubes[i] + cubes[j]]++;

	bool solved = false;
	for (int i = m; i >= 1; i--)
		if (sum[i] >= 2) {
			std::cout << i;
			solved = true;
			break;
		}
	if (!solved)
		printf("none");
}

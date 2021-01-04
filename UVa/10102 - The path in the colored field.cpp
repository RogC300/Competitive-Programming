/*
 * 10102 - The path in the colored field.cpp
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int distance(std::pair<int, int> a, std::pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	int n;
	while (std::cin >> n) {
		std::vector<std::pair<int, int>> one, three;
		std::vector<int> minMax;
		int min;
		for (int i = 0; i < n; i++)
			for (int j = 0, x; j < n; j++) {
				char in;
				std::cin >> in;
				x = in - '0';
				if (x == 1)
					one.push_back(std::make_pair(i, j));
				if (x == 3)
					three.push_back(std::make_pair(i, j));
			}
		for (int i = 0; i < (int) one.size(); i++) {
			min = 999999;
			for (int j = 0; j < (int) three.size(); j++)
				min = std::min(min, distance(one[i], three[j]));
			minMax.push_back(min);
		}
		std::sort(minMax.rbegin(), minMax.rend());
		std::cout << minMax[0] << std::endl;
	}
}

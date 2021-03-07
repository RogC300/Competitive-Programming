/*
 * Surmising a Sprinter’s Speed.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> m(n);

	for (int i = 0; i < n; i++)
		std::cin >> m[i].first >> m[i].second;

	std::sort(m.begin(), m.end());

	double max = 0;
	for (int i = 1; i < n; i++) {
		int time = m[i].first - m[i - 1].first;
		int dis = abs(m[i].second - m[i - 1].second);

		double speed = (double) dis / time;

		if (speed > max)
			max = speed;
	}
	std::cout << std::fixed << std::setprecision(10) << max;
}

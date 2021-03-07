/*
 * Transit Woes.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int cur, class_start, num_b;
	std::vector<int> walk, bus_t, intervals;

	std::cin >> cur >> class_start >> num_b;

	walk.resize(num_b + 1), bus_t.resize(num_b);
	intervals.resize(num_b);
	for (int i = 0; i < num_b + 1; i++)
		std::cin >> walk[i];
	for (int i = 0; i < num_b; i++)
		std::cin >> bus_t[i];
	for (int i = 0; i < num_b; i++)
		std::cin >> intervals[i];

	cur += walk[0];
	for (int i = 0; i < num_b; i++) {
		cur += intervals[i]
				- (cur % intervals[i] == 0 ? intervals[i] : cur % intervals[i]);
		cur += bus_t[i], cur += walk[i + 1];
	}
	std::cout << (cur <= class_start ? "yes" : "no");
}

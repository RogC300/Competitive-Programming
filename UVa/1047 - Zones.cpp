/*
 * 1047 - Zones.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

std::vector<int> p, final;
std::map<std::vector<int>, int> m;
int totalTowers, builtTowers, overlap, max = 0;
// I gave up
int inclusion_exclusion(std::vector<int> t) {
	int sum = 0;
	for (auto it = m.begin(); it != m.end(); it++)
		if (std::includes(t.begin(), t.end(), it->first.begin(),
				it->first.end()))
			sum += (it->first.size() % 2 == 0 ? -1 * it->second : it->second);

	return sum;
}

void findSum(int builtTowers, int i, std::vector<int> path, int pIndex) {
	if (builtTowers == 0) {
		if (inclusion_exclusion(path) > max)
			max = inclusion_exclusion(path), final = path;
		return;
	}
	for (int k = i; k <= totalTowers; k++)
		path[pIndex] = k, findSum(builtTowers - 1, k + 1, path, pIndex + 1);
}

void print_vector(std::vector<int> v) {
	for (int i = 0; i < (int) v.size(); i++)
		std::cout << v[i] << (i == (int) v.size() - 1 ? "\n" : " ");
}

int main() {
	std::cin >> totalTowers >> builtTowers;
	for (int i = 1, people; i <= totalTowers; i++) {
		std::vector<int> a = { i };
		std::cin >> people, m[a] = people;
	}
	p.resize(builtTowers);
	std::cin >> overlap;
	for (int i = 0, t, people; i < overlap; i++) {
		std::vector<int> lap;
		std::cin >> t;
		for (int j = 0, temp; j < t; j++)
			std::cin >> temp, lap.push_back(temp);
		std::sort(lap.begin(), lap.end());
		std::cin >> people;
		m[lap] = people;
	}
	findSum(builtTowers, 1, p, 0);
	std::cout << max << std::endl;
	print_vector(final);

}


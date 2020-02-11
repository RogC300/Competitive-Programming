/*
 * Planting Trees.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int num_trees, max = 0;
	std::vector<int> trees;
	std::cin >> num_trees;
	for (int i = 0, t; i < num_trees; i++)
		std::cin >> t, trees.push_back(t);
	std::sort(trees.rbegin(), trees.rend());
	for (int i = 0; i < num_trees; i++)
		max = std::max(trees[i] + i + 1, max);
	std::cout << max + 1;
}

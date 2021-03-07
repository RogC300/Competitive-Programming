/*
 * 10226 - Hardwood Species.cpp
 *
 *      Author: Roger
 */
#include <iostream>
#include <map>
#include <iterator>
#include <iomanip>

int main() {
	int runs;
	scanf("%d", &runs);
	getchar();
	getchar();
	while (runs--) {
		std::string tree;
		std::map<std::string, int> trees;
		int totalTrees = 0;
		while (getline(std::cin, tree)) {
			if (tree == "")
				break;
			trees[tree]++, totalTrees++;
		}
		for (std::map<std::string, int>::iterator itr = trees.begin();
				itr != trees.end(); itr++)
			std::cout << itr->first << " " << std::fixed << std::setprecision(4)
					<< ((double) itr->second / (double) totalTrees * 100.0)
					<< std::endl;
		if (runs)
			puts("");
	}
}

/*
 * 10567 - Helping Fill Bates.cpp
 */
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int main() {
	std::string input, candidates;
	int cases;
	std::vector<std::vector<int>> states(200);
	std::cin >> input >> cases;
	for (int i = 0; i < (int) input.length(); i++)
		states[input[i]].push_back(i);

	while (cases--) {
		std::cin >> candidates;
		int index = -1, start;
		bool matched = true;
		for (int i = 0; i < (int) candidates.length(); i++) {
			std::vector<int>::iterator upper = std::upper_bound(
					states[candidates[i]].begin(), states[candidates[i]].end(),
					index);
			index = upper - states[candidates[i]].begin();
			if (upper == states[candidates[i]].end())
				matched = false;
			index = states[candidates[i]][index];
			if (i == 0)
				start = index;
		}
		if (matched)
			printf("Matched %d %d\n", start, index);
		else
			printf("Not matched\n");
	}
}

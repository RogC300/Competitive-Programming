/*
 * 231 - Testing the CATCHER.cpp
 */
#include <iostream>
#include <vector>

void p_multi_v(std::vector<std::vector<int>> v) {
	for (int i = 0; i < (int) v.size(); i++)
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << v[i][j] << (j == (int) v[i].size() - 1 ? "\n" : " ");
}

int LDS(std::vector<int> d) { // Longest Decreasing Subsequence
	std::vector<std::vector<int>> l(d.size());
	l[0].push_back(d[0]);

	for (int i = 1; i < (int) d.size(); i++) {
		for (int j = 0; j < i; j++)
			if (d[j] >= d[i] && l[j].size() + 1 > l[i].size()) // change d[j] < d[i] for LIS
				l[i] = l[j];
		l[i].push_back(d[i]);
	}
	int max = 0;
	for (int i = 0; i < (int) l.size(); i++)
		max = std::max(max, (int) l[i].size());
//	p_multi_v(l);
	return max;
}

int main() {
	int count = 0;
	while (1) {
		int input;
		std::vector<int> heights;

		while (std::cin >> input && input != -1)
			heights.push_back(input);
		if (heights.size() == 0)
			break;
		if (count)
			puts("");
		printf("Test #%d:\n  maximum possible interceptions: %d\n", ++count,
				LDS(heights));
	}
}

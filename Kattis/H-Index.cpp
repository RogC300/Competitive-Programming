/*
 * H-Index.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int numOfPapers, hIndex = 0;
	std::cin >> numOfPapers;
	std::vector<int> papers(numOfPapers);
	for (int i = 0; i < numOfPapers; i++)
		std::cin >> papers[i];

	std::sort(papers.begin(), papers.end());

	for (int i = 0; i < numOfPapers; i++)
		if (papers[i] >= numOfPapers - i) {
			hIndex = numOfPapers - i;
			break;
		}
	std::cout << hIndex;
}

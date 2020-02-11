/*
 * Ragged Right.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
	std::vector<std::string> paragraph;
	std::string in;
	int longest = 0, rag = 0;

	while (getline(std::cin, in))
		paragraph.push_back(in);

	for (int i = 0; i < (int) paragraph.size(); i++)
		longest = std::max(longest, (int) paragraph[i].length());

	for (int i = 0; i < (int) paragraph.size() - 1; i++)
		rag += pow(longest - paragraph[i].length(), 2);

	std::cout << rag;
}

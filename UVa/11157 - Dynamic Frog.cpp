/*
 * 11157 - Dynamic Frog.cpp
 */
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

void p_v(std::vector<int> v) {
	for (int i = 0; i < (int) v.size(); i++)
		std::cout << v[i] << (i == (int) v.size() - 1 ? "\n" : " ");
	puts("");
}

int main() {
	int cases, num_of_rocks, pond_length, max_jump;
	std::vector<int> skip_first, skip_second;
	bool first = true;
	std::string rock_place;

	std::cin >> cases;
	for (int c = 1; c <= cases; c++) {
		std::cin >> num_of_rocks >> pond_length;
		max_jump = 0, skip_first.clear(), skip_second.clear(), first = true;
		for (int i = 0; i < num_of_rocks; i++) {
			std::cin >> rock_place;
			int index = stoi(rock_place.substr(2, rock_place.length()));
			if (rock_place[0] == 'S')
				first == true ?
						skip_second.push_back(index) :
						skip_first.push_back(index), first = !first;
			else
				skip_second.push_back(index), skip_first.push_back(index);
		}
		std::sort(skip_second.begin(), skip_second.end()), std::sort(
				skip_first.begin(), skip_first.end());
		skip_second.push_back(pond_length), skip_first.push_back(pond_length);
//	p_v (skip_second), p_v (skip_first);
		for (int i = 0, current = 0; i < (int) skip_second.size(); i++)
			max_jump = std::max(max_jump, skip_second[i] - current), current =
					skip_second[i];
		for (int i = 0, current = 0; i < (int) skip_first.size(); i++)
			max_jump = std::max(max_jump, skip_first[i] - current), current =
					skip_first[i];

		printf("Case %d: %d\n", c, max_jump);
	}
}

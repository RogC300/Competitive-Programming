/*
 * 12210 - A Match Making Problem.cpp
 */
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int num_of_bachelors, num_of_spinsters, case_count = 1, min;
	std::vector<int> bachelors, spinsters;
	while (std::cin >> num_of_bachelors >> num_of_spinsters
			&& num_of_bachelors != 0 && num_of_spinsters != 0) {
		bachelors.clear(), spinsters.clear(), min = 61;
		for (int i = 0, b; i < num_of_bachelors; i++)
			std::cin >> b, bachelors.push_back(b), min = std::min(b, min);
		for (int i = 0, s; i < num_of_spinsters; i++)
			std::cin >> s, spinsters.push_back(s);

		if (num_of_bachelors <= num_of_spinsters)
			printf("Case %d: 0\n", case_count++);
		else
			printf("Case %d: %d %d\n", case_count++,
					num_of_bachelors - num_of_spinsters, min);
	}
}

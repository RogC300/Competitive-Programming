/*
 * RationalLee.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int num_int, num_fri, fri_ind, restart_ind, tc;
	long long int sum;
	bool maxed;
	std::vector<std::pair<int, int>> min_max;
	std::vector<int> ints, fri;

	std::cin >> tc;
	while (tc--) {
		std::cin >> num_int >> num_fri;
		min_max.assign(num_fri, { -2e9, 2e9 }), maxed = false;
		ints.resize(num_int), fri.resize(num_fri);
		fri_ind = restart_ind = sum = 0;

		for (int i = 0; i < num_int; i++)
			std::cin >> ints[i];
		for (int i = 0; i < num_fri; i++)
			std::cin >> fri[i];
		std::sort(ints.begin(), ints.end(), [](int a, int b) {
			return a > b;
		});
		std::sort(fri.begin(), fri.end());

		for (int i = 0; i < num_int; i++) {
			if (fri_ind == num_fri)
				fri_ind = restart_ind, maxed = true;

			min_max[fri_ind].first = std::max(min_max[fri_ind].first, ints[i]);
			min_max[fri_ind].second = std::min(min_max[fri_ind].second, ints[i]);
			fri[fri_ind]--;
			if (maxed && fri[fri_ind] == 0) {
				fri_ind++;
				continue;
			}
			if (fri[fri_ind] == 0)
				restart_ind++;
			if (maxed == false)
				fri_ind++;
		}

		for (int i = 0; i < num_fri; i++)
			sum += min_max[i].first + min_max[i].second;

		std::cout << sum << "\n";
	}
}

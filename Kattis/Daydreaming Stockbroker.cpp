/*
 * Daydreaming Stockbroker.cpp
 */
#include <iostream>
#include <algorithm>

int main() {
	int num_days, days[366];
	long long total = 100, tmp, max = 100000;
	std::cin >> num_days;
	for (int i = 0; i < num_days; i++)
		std::cin >> days[i];

	tmp = days[0];
	for (int i = 1; i < num_days; i++)
		if (days[i] < days[i - 1])
			total += (long long)(days[i - 1] - tmp) * std::min(total / tmp, max), tmp =
					days[i];
	if (days[num_days - 1] - tmp > 0)
		total += (long long) (days[num_days - 1] - tmp) * std::min(total / tmp, max);
	std::cout << total;
}

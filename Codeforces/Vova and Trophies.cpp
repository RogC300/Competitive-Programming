/*
 * Vova and Trophies.cpp
 *
 *      Author: Roger
 */
#include <iostream>
#include <vector>
#include <cmath>

int solve(std::vector<char> trophies) {
	int sum = 0, row = 0, found = 0, max = 0;
	std::vector<int> goldRows;
	trophies.push_back('S');
	for (int i = 0; i <= (int) trophies.size(); i++) {
		if (trophies[i] == 'G')
			row++;
		else if (trophies[i] == 'S')
			goldRows.push_back(row), row = 0;
	}
	for (int i = 0; i < (int) goldRows.size(); i++)
		if (goldRows[i] > 0) {
			found++;
			max = std::max (max, goldRows[i]);
		}

	if (found == 1)
		for (int i = 0; i < (int) goldRows.size(); i++)
			if (goldRows[i] > 0)
				return goldRows[i];
	if (found == 0)
		return 0;

	for (int i = 0; i < (int) goldRows.size() - 1; i++)
		sum = std::max(goldRows[i] + goldRows[i + 1], sum);

	if (found >= 3)
		return sum + 1;
	else if (max == sum && found > 1)
		return sum + 1;
	else
		return sum;
}

int main() {
	int trophyAmount;
	std::cin >> trophyAmount;
	std::vector<char> trophies(trophyAmount);
	for (int i = 0; i < trophyAmount; i++)
		std::cin >> trophies[i];
	std::cout << solve(trophies);
}

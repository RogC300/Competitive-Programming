/*
 * Bank Queue.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int smallestElement(std::vector<int> people) {
	int size = people.size();
	for (int i = size - 1; i >= 0; i--)
		if (people[i] != 0)
			return people[i];
	return 0;
}

int smallestElementRid(std::vector<int>& people) {
	int size = people.size(), answer = 0;
	for (int i = size - 1; i >= 0; i--)
		if (people[i] != 0) {
			answer = people[i];
			people[i] = 0;
			break;
		}
	return answer;
}

int main() {
	int numPeople, timeUntilClose, sum = 0, add;
	std::vector<std::vector<int>> people;
	std::cin >> numPeople >> timeUntilClose;
	people.resize(timeUntilClose);

	for (int i = 0; i < numPeople; i++) {
		int tempWorth, tempTime;
		std::cin >> tempWorth >> tempTime;
		people[tempTime].push_back(tempWorth);
	}

	for (int i = 0; i < timeUntilClose; i++)
		if (people[i].size() != 0)
			std::sort(people[i].begin(), people[i].end());
/*
	for (int i = 0; i < (int)people.size(); i++){
		for (int j = 0; j < (int)people[i].size(); j++)
			std::cout << people[i][j] << " ";
		std::cout << std::endl;
	}*/
	for (int i = timeUntilClose - 1; i >= 0; i--) {
		if (people[i].size() != 0) {
			add = smallestElement(people[i]);
			bool found = false;
			int f;
			for (int j = i + 1; j < timeUntilClose; j++)
				if (smallestElement(people[j]) >= add && people[j].size() != 0 && smallestElement(people[j]) != 0) {
					add = smallestElement(people[j]);
					f = j;
					found = true;
				}
			sum += add;
			if (found) smallestElementRid(people[f]);
			else smallestElementRid(people[i]);

		//	std::cout << add;
		//	if (found) std::cout << "found\n";
		//	else std::cout << "not\n";

		}
		else {
			add = 0;
			for (int j = i + 1; j < timeUntilClose; j++)
				if (smallestElement(people[j]) != 0)
					add = std::max (add, smallestElement(people[j]));
			sum += add;
		}
	}

	std::cout << sum;
}

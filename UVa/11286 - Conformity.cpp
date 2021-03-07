/*
 * 11286 - Conformity.cpp
 *
 *      Author: Roger
 */
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <vector>
#include <algorithm>

int main() {
	while (true) {
		int numPeople, largest = 0, popular = 0;
		std::cin >> numPeople;
		if (numPeople == 0)
			break;
		std::map<std::string, int> courses;

		for (int i = 0; i < numPeople; i++) {
			std::string code = "";
			std::vector<int> course;
			for (int i = 0, t; i < 5; i++) {
				std::cin >> t;
				course.push_back(t);
			}
			std::sort(course.begin(), course.end());
			for (int i = 0; i < 5; i++)
				code += std::to_string(course[i]);
			courses[code]++;
		}
		for (std::map<std::string, int>::iterator itr = courses.begin();
				itr != courses.end(); itr++)
			largest = std::max(largest, itr->second);

		for (std::map<std::string, int>::iterator itr = courses.begin();
				itr != courses.end(); itr++)
			if (itr->second == largest)
				popular += itr->second;
		printf("%d\n", popular);
	}
}

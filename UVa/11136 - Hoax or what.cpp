/*
 * 11136 - Hoax or what.cpp
 *
 *      Author: Roger
 */
#include <set>
#include <iostream>

int main() {
	int days;
	while (std::cin >> days, days) {
		long long int cost = 0;
		std::multiset<int> bills;
		for (int i = 0, numBills, b; i < days; i++) {
			std::cin >> numBills;
			while (numBills--) {
				std::cin >> b;
				bills.insert(b);
			}
			std::multiset<int>::iterator begin = bills.begin(), end =
					--bills.end();
			cost += *end - *begin;
			bills.erase(begin);
			bills.erase(end);
		}
		std::cout << cost << std::endl;
	}
}

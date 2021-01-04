/*
 * 10107 - What is the Median.cpp
 *
 *      Author: Roger
 */
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::vector<long long int> vec;
	long long int push, med;
	while (scanf ("%I64d", &push) == 1) {
		vec.push_back(push);
		std::sort(vec.begin(), vec.end());
		med = 0;
		if (vec.size() % 2 == 0) {
			med += vec[vec.size() / 2];
			med += vec[vec.size() / 2 - 1];
			med /= 2;
		} else
			med += vec[vec.size() / 2];
		std::cout << med << std::endl;
	}
}

/*
 * Candy Division.cpp
 */
#include <iostream>
#include <cmath>
#include <set>

int main() {
	long long int in;
	std::set<long long int> out;

	std::cin >> in;
	for (long long int i = 1; i <= sqrt(in); i++)
		if (in % i == 0)
			out.insert(i), out.insert(in / i);

	for (auto i : out)
		std::cout << i - 1 << " ";
}

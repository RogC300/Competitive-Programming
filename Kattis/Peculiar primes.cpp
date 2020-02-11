/*
 * Peculiar primes.cpp
 */
#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

std::set<int> seen;
std::vector<int> primes, limit;
int num_primes, l, r;
long long int temp;

int log(double x, double b) {
	return (int) (log(x) / log(b)) + 1;
}

void recurse(int i, long long int num) {
	if (num <= r && num >= l)
		seen.insert(num);
	if (i == num_primes || num > r)
		return;

	for (int j = 0; j <= limit[i]; j++) {
		temp = num * pow(primes[i], j);
		if (temp > r)
			break;
		recurse(i + 1, temp);
	}
}

void out() {
	std::vector<int> temp;
	if (seen.size()) {
		for (auto i : seen)
			temp.push_back(i);
		std::cout << temp[0];
		for (int i = 1; i < (int) temp.size(); i++)
			std::cout << "," << temp[i];
	} else
		std::cout << "none";
	std::cout << "\n";
}

int main() {
	while (std::cin >> num_primes && num_primes != 0) {
		primes.resize(num_primes), seen.clear(), limit.clear();

		for (int i = 0; i < num_primes; i++)
			std::cin >> primes[i];
		std::sort(primes.begin(), primes.end());

		std::cin >> l >> r;

		for (int i = 0; i < num_primes; i++)
			limit.push_back(log(r, primes[i]));

		recurse(0, 1);
		out();
	}
}

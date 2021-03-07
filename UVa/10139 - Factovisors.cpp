/*
 * 10139 - Factovisors.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define max 46341

std::vector<int> primes;

void sieve() {
	std::vector<bool> sieve(max, true);
	primes.push_back(2);

	for (int i = 4; i < max; i += 2)
		sieve[i] = false;

	for (int i = 3; i < max; i += 2)
		if (sieve[i]) {
			for (int j = i * i; j < max; j += i)
				sieve[j] = false;
			primes.push_back(i);
		}
}

std::map<int, int> prime_factorization(int n) {
	int current = 2, index = 0, original = n;
	std::map<int, int> factors;
	while (current * current <= original && index < (int) primes.size()) {
		while (n % current == 0)
			n /= current, factors[current]++;
		current = primes[++index];
	}
	if (n != 1)
		factors[n]++;
	return factors;
}

int get_powers(int n, int p) {
	int res = 0;
	for (long long power = p; power <= n; power *= p)
		res += n / power;
	return res;
}

int main() {
	sieve();
	bool divisible;
	int factorial, divisor;
	std::map<int, int> divisor_factors;

	while (std::cin >> factorial >> divisor) {
		divisor_factors.clear(), divisible = true;
		divisor_factors = prime_factorization(divisor);

		if (divisor != 0)
			for (auto i : divisor_factors)
				if (i.second > get_powers(factorial, i.first)) {
					divisible = false;
					break;
				}
		std::cout << divisor << (divisible ? " divides " : " does not divide ")
				<< factorial << "!\n";
	}
}

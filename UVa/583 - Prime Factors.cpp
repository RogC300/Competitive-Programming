/*
 * 583 - Prime Factors.cpp
 */
#include <iostream>
#include <vector>

#define MAX 46341

std::vector<int> primes;

void sieve() {
	std::vector<bool> sieve(MAX, true);

	sieve[0] = sieve[1] = false;

	for (long long i = 2; i < MAX; i++)
		if (sieve[i]) {
			for (long long j = i * i; j < MAX; j += i)
				sieve[j] = false;
			primes.push_back(i);
		}
}

int main() {
	sieve();
	int n, current, original, index;
	bool f;
	std::vector<int> factors;

	while (std::cin >> n && n != 0) {
		std::cout << n << " = ", f = false, factors.clear();
		n < 0 ? factors.push_back(-1), n *= -1 : 1;

		current = 2, index = 0, original = n;
		while (current * current <= original && index < (int) primes.size()) {
			while (n % current == 0)
				n /= current, factors.push_back(current);
			current = primes[++index];
		}
		if (n != 1)
			factors.push_back(n);

		for (int i = 0; i < (int) factors.size(); i++)
			std::cout << (f == true ? " x " : "") << factors[i], f = true;
		puts("");
	}
}

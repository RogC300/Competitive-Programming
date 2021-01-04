/*
 * 294 - Divisors.cpp
 */
#include <iostream>
#include <vector>

std::vector<int> primes;

void sieve() {
	std::vector<bool> v(31630, true);

	primes.push_back(2);
	for (int i = 4; i < 31630; i += 2)
		v[i] = false;

	for (int i = 3; i < 31630; i += 2)
		if (v[i]) {
			for (int j = i * i; j < 31630; j += i)
				v[j] = false;
			primes.push_back(i);
		}
}

int num_divisors(int n) {
	int current = 2, index = 0, original = n, divisors = 1, power;
	while (current * current <= original && index < (int) primes.size()) {
		power = 0;
		while (n % current == 0)
			n /= current, power++;
		divisors *= power + 1;
		current = primes[++index];
	}
	if (n != 1)
		divisors *= 2;
	return divisors;
}

int main() {
	sieve();
	int lower, upper, tc, number, divisors;
	std::cin >> tc;
	while (tc--) {
		std::cin >> lower >> upper, divisors = 0;
		for (int i = lower, d; i <= upper; i++)
			d = num_divisors(i), d > divisors ? divisors = d, number = i : 1;
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", lower,
				upper, number, divisors);
	}
}

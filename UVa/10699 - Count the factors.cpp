/*
 * 10699 - Count the factors.cpp
 */
#include <iostream>
#include <vector>

std::vector<int> primes;

void sieve() {
	std::vector<bool> v(1010, true);
	primes.push_back(2);
	for (int i = 4; i < 1010; i += 2)
		v[i] = false;

	for (int i = 3; i < 1010; i += 2)
		if (v[i]) {
			for (int j = i * i; j < 1010; j += i)
				v[j] = false;
			primes.push_back(i);
		}
}

int num_factors(int n) {
	int current = 2, index = 0, original = n, factors = 0;
	bool add;

	while (current * current <= original && index < (int) primes.size()) {
		add = false;
		while (n % current == 0)
			n /= current, add = true;
		add ? factors++ : 1;
		current = primes[++index];
	}
	if (n != 1)
		factors++;
	return factors;
}

int main() {
	sieve();
	int n;
	while (std::cin >> n && n != 0)
		printf("%d : %d\n", n, num_factors(n));
}

/*
 * Number Game.cpp
 */
#include <iostream>
#include <vector>

std::vector<int> primes;

void sieve() {
	std::vector<bool> arr(23000, true);

	for (int i = 3; i < 23000; i += 2)
		if (arr[i]) {
			for (int j = i; j < 23000; j += i)
				arr[j] = false;
			primes.push_back(i);
		}
}

bool is_prime(int n) {
	for (int i = 0; i < (int) primes.size() && primes[i] <= n; i++)
		if (n % primes[i] == 0) {
			n /= primes[i];
			return n == 1;
		}
	return true;
}

bool num_factors(int n) {
	int num_twos = 0;

	while (n % 2 == 0)
		n /= 2, num_twos++;

	if (n == 1)
		return false;
	if (!is_prime(n))
		return true;
	if (num_twos == 1)
		return false;
	return true;
}

int main() {
	int n, tc;

	std::cin >> tc, sieve();

	while (tc--) {
		std::cin >> n;
		if (n == 2 || (n % 2 == 1 && n > 1))
			std::cout << "Ashishgup\n";
		else if (n % 2 == 0 && num_factors(n))
			std::cout << "Ashishgup\n";
		else
			std::cout << "FastestFinger\n";
	}
}

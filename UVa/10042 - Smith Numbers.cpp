/*
 * 10042 - Smith Numbers.cpp
 */
#include <iostream>
#include <vector>
#include <cmath>

#define max 100005

std::vector<int> primes;

void prime_find() {
	std::vector<bool> sieve(max, true);

	for (int i = 2; i < max; i++)
		if (sieve[i] == true) {
			primes.push_back(i);
			for (int j = i * 2; j < max; j += i)
				sieve[j] = false;
		}
}

int sum_digits(int n) {
	int sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

bool smith(int n) {
	int sum1 = sum_digits(n), sum2 = 0;
	int root = n;
	int factors = 0, index = 0;
	while (n != 1 && primes[index] <= sqrt(root)) {
		if (n % primes[index] == 0) {
			sum2 += sum_digits(primes[index]);
			n /= primes[index];
			factors++;
		} else
			index++;
	}

	if (n != 1)
		sum2 += sum_digits(n), factors++;
	if (factors == 1)
		return false;

//	std::cout << sum1 << " " << sum2 << "\n";
	if (sum1 == sum2)
		return true;
	return false;
}

int main() {
	prime_find();

	int tc, n;
	std::cin >> tc;
	while (tc--) {
		std::cin >> n;
		for (int i = n + 1;; i++)
			if (smith(i)) {
				std::cout << i << "\n";
				break;
			}
//		smith (n);
	}
}

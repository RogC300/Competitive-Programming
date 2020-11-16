/*
 * Prime Square.cpp
 */
#include <iostream>
#include <vector>

std::vector<int> primes;
std::vector<bool> sieve(1e9, true);

void sieve_of_er() {
	sieve[1] = false;
	for (int i = 2; i * i < 100000; i++)
		if (sieve[i]) {
			primes.push_back(i);
			for (int j = i + i; j < 100000; j += i)
				sieve[j] = false;
		}
}

void solve() {
	int n, diff;
	std::cin >> n;

//	for (auto i : primes)
//		std::cout << i << " ";
//	puts ("\n");

	for (auto i : primes)
		if (i >= n && sieve[i] && !sieve[i - (n - 1)]) {
			diff = (i - (n - 1));
			break;
		}

//	std::cout << diff << "\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			std::cout << (i == j ? diff : 1) << " ";
		puts("");
	}
}

int main() {
	int tc = 1;
	std::cin >> tc;
	sieve_of_er();
	while (tc--)
		solve();
}

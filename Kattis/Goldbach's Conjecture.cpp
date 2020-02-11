/*
 * Goldbach's Conjecture.cpp
 */
#include <iostream>
#include <vector>

void sieve(std::vector<bool> &primes) {
	primes.assign(35000, true);
	primes[0] = primes[1] = false;

	for (int i = 4; i < 35000; i += 2)
		primes[i] = false;
	for (int i = 3; i < 35000; i += 2)
		if (primes[i])
			for (int j = i + i; j <= 35000; j += i)
				primes[j] = false;

}

std::vector<std::pair<int, int>> goldbach(int p, std::vector<bool> primes) {
	int a = 2, b = p - 2;
	std::vector<std::pair<int, int>> pairs;
	while (b >= a) {
		if (primes[a] && primes[b])
			pairs.push_back( { a, b });
		b--, a++;
	}
	return pairs;
}

int main() {
	std::vector<bool> primes;
	std::vector<std::pair<int, int>> pairs;
	int n, p;

	std::cin >> n, sieve(primes);
	while (n--) {
		std::cin >> p, pairs = goldbach(p, primes);

		printf("%d has %d representation(s)\n", p, (int) pairs.size());
		for (auto i : pairs)
			printf("%d+%d\n", i.first, i.second);
		puts("");
	}
}

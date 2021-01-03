/*
 * Pretty Average Primes.cpp
 */
#include <iostream>
#include <vector>

std::vector<bool> pr(2000001, true);

void solve() {
	int sum;
	std::cin >> sum, sum *= 2;
	for (int i = 1; i < sum; i++)
		if (pr[i] && pr[sum - i]) {
			std::cout << i << "  " << sum - i << "\n";
			break;
		}
}

int main() {
	int q;
	std::cin >> q;
	pr[1] = false;
	for (int i = 2; i * i <= 2000000; i++)
		if (pr[i] == true)
			for (int j = i * 2; j <= 2000000; j += i)
				pr[j] = false;
	while (q--)
		solve();
}

/*
 * 11526 - H(n).cpp
 */
#include <iostream>
#include <cmath>

long long H(int n) {
	long long ans = 0;
	int j = 1, k = n, l, r;
	while (k != 0) {
		r = n / j, l = n / (j + 1);
		ans += (long long) j * (r - l);
		k -= r - l, j = n / (k != 0 ? k : 1);
	}
	return ans;
}

int main() {
	int tc;
	long long n;
	std::cin >> tc;
	while (tc--) {
		std::cin >> n;
		std::cout << (n > 0 ? H(n) : 0) << "\n";
	}
}

/*
 * Buying Torches.cpp
 */
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
	long long int x, y, k, ans;
	int tc = 1;
	std::cin >> tc;

	while (tc--) {
		std::cin >> x >> y >> k, x--;
		ans = (k * y + k - 1) / x + k;
		if ((k * y + k - 1) % x > 0)
			ans++;
		std::cout << ans << "\n";
	}
}

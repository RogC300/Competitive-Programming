/*
 * Fadi and LCM.cpp
 */
#include <iostream>

typedef long long int ll;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	ll x, ans;

	std::cin >> x;

	for (ll i = 1; i * i <= x; i++)
		if (x % i == 0 && lcm(i, x / i) == x)
			ans = i;
	std::cout << ans << " " << x / ans;
}

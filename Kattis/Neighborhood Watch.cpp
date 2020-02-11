/*
 * Neighborhood Watch.cpp
 */
#include <iostream>
#include <vector>

typedef long long int ll;

int main() {
	ll n, k, safe_routes;
	std::cin >> n >> k;

	std::vector<ll> safe_houses;
	safe_houses.push_back(0);
	for (int i = 0, h; i < k; i++)
		std::cin >> h, safe_houses.push_back(h);
	safe_houses.push_back(n + 1);
	safe_routes = n * (n + 1) / 2;
	for (ll i = 1, unsafe_routes; i < (int) safe_houses.size(); i++) {
		unsafe_routes = safe_houses[i] - safe_houses[i - 1] - 1;
		safe_routes -= (unsafe_routes + 1) * unsafe_routes / 2;
	}
	std::cout << safe_routes;
}

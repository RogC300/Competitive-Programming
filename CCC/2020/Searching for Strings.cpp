/*
 * Searching for Strings.cpp
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

typedef long long int ll;

ll prime = 2003, prime_two = 131, mod = 1e9 + 9;

int count(std::string sub, std::string full) {
	std::set<std::pair<ll, ll>> set;
	std::vector<int> f_sub(26, 0), f_full(26, 0);

	ll h_full_1 = 0, h_full_2 = 0, power = 1, power_two = 1;
	int sub_len = sub.length(), full_len = full.length();

	for (int i = 0; i < sub_len; i++) {
		power = (power * prime) % mod;
		power_two = (power_two * prime_two) % mod;
		f_sub[sub[i] - 'a']++;
	}

	for (int i = 0; i < full_len; i++) {
		h_full_1 = (h_full_1 * prime + full[i]) % mod;
		h_full_2 = (h_full_2 * prime_two + full[i]) % mod;

		f_full[full[i] - 'a']++;

		if (i >= sub_len) {
			h_full_1 -= power * full[i - sub_len] % mod;
			if (h_full_1 < 0)
				h_full_1 += mod;
			h_full_2 -= power_two * full[i - sub_len] % mod;
			if (h_full_2 < 0)
				h_full_2 += mod;

			f_full[full[i - sub_len] - 'a']--;
		}
		if (f_full == f_sub && set.count( { h_full_1, h_full_2 }) == 0)
			set.insert( { h_full_1, h_full_2 });
	}
	return set.size();
}

int main() {
	std::string a, b;
	std::cin >> a >> b;
	std::cout << count(a, b);
}

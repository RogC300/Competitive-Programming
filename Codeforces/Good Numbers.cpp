/*
 * Good Numbers.cpp
 */
#include <iostream>
#include <vector>

typedef long long ll;

ll int_pow(ll b, ll e) {
	return e == 0 ? 1 : b * int_pow(b, e - 1);
}

int main() {
	ll n, t, sum;
	int index, tc;
	std::vector<int> base_t;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n;
		t = n, base_t.clear(), index = -1, sum = 0;

		while (t != 0)
			base_t.push_back(t % 3), t /= 3;
		base_t.push_back(0);

		for (int i = base_t.size() - 1; i >= 0; i--)
			if (base_t[i] == 2) {
				index = i;
				break;
			}

		if (index == -1) {
			std::cout << n << "\n";
			continue;
		}

		for (int i = index + 1; i < (int) base_t.size(); i++)
			if (base_t[i] == 0) {
				base_t[i] = 1, index = i;
				break;
			}
		for (int i = index - 1; i >= 0; i--)
			base_t[i] = 0;

		for (int i = 0; i < (int) base_t.size(); i++)
			if (base_t[i] == 1)
				sum += int_pow(3, i);
		std::cout << sum << "\n";
	}
}

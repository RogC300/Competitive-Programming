/*
 * Boboniu Chats with Du.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int

void order(std::vector<ll> &a, std::vector<ll> &b) {
	std::sort(a.rbegin(), a.rend());
	std::sort(b.rbegin(), b.rend());

	for (int i = 1; i < (int) a.size(); i++)
		a[i] += a[i - 1];
	for (int i = 1; i < (int) b.size(); i++)
		b[i] += b[i - 1];
}

int main() {
	int n, d, threshold, a_size, b_size;
	ll ans = 0;
	std::vector<ll> above, below;

	std::cin >> n >> d >> threshold;

	for (ll i = 0, in; i < n; i++) {
		std::cin >> in;
		in > threshold ? above.push_back(in) : below.push_back(in);
	}
	a_size = above.size(), b_size = below.size();

	if (a_size == 0) {
		ll sum = 0;
		for (auto i : below)
			sum += i;
		std::cout << sum;
		return 0;
	}

	order(above, below);

	for (int i = (a_size + d) / (d + 1) - 1; i < a_size; i++)
		if ((ll) i * (d + 1) + 1 <= n) {
			ll ind = std::min((ll) b_size - 1, n - ((ll) i * (d + 1) + 1) - 1);
			ans = std::max(ans, above[i] + (ind >= 0 ? below[ind] : 0));
		}
	std::cout << ans;
}

/*
 The written solution is a bit confusing, basically you just go through the possibilities of
 removing the numbers above the threshold for the numbers below. So you say, what if I take the
 minimum amount of numbers above the threshold (thats the largest), and take the largest remaining
 numbers below the threshold. For example, sample two we have 4 numbers above the threshold.
 Because the number of muzzle days are 2 that means the minimum number of numbers above that
 we can take is 2, because its impossible to muzzle the 3 others at once. So you pick the 2 largest
 and then figure out the remaining days you have and take the ones below occordingly, repeat
 for taking more days that muzzle that choose the max number.
 */

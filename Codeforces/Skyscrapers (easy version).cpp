/*
 * Skyscrapers (easy version).cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

typedef long long int ll;

ll pivot(int p, std::vector<ll> &v, int &n) {
	ll heights = v[p], cur = v[p];

	for (int i = p + 1; i < n; i++)
		cur = std::min((ll) v[i], cur), heights += cur;

	cur = v[p];
	for (int i = p - 1; i >= 0; i--)
		cur = std::min((ll) v[i], cur), heights += cur;

	return heights;
}

void out_p(int p, std::vector<ll> &v, int &n) {
	std::vector<ll> beg, end;
	ll cur = v[p];

	for (int i = p + 1; i < n; i++)
		cur = std::min(v[i], cur), end.push_back(cur);
	cur = v[p];
	for (int i = p - 1; i >= 0; i--)
		cur = std::min(v[i], cur), beg.push_back(cur);
	std::reverse(beg.begin(), beg.end());

	for (int i = 0; i < (int) beg.size(); i++)
		std::cout << beg[i] << " ";
	std::cout << v[p] << " ";
	for (int i = 0; i < (int) end.size(); i++)
		std::cout << end[i] << " ";
}

int main() {
	int n;
	ll max_h = 0, piv;
	std::vector<ll> max;

	std::cin >> n, max.resize(n);

	for (int i = 0; i < n; i++)
		std::cin >> max[i];

	for (ll i = 0, p; i < n; i++) {
		p = pivot(i, max, n);
		if (p > max_h)
			max_h = p, piv = i;
	}
	out_p(piv, max, n);
}

/*
 * Absolutely Acidic.cpp
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
	map<int, int> m;
	map<int, set<int>> freq;
	int n, ans = 0;
	std::cin >> n;

	for (int i = 0, in; i < n; i++)
		std::cin >> in, m[in]++;

	for (auto i : m)
		freq[-i.second].insert(i.first);

	set<int> a, b;
	a = freq.begin()->second;
	b = next(freq.begin(), 1)->second;

	if (a.size() > 1)
		ans = *a.rbegin() - *a.begin();
	else
		ans = max(abs(*a.begin() - *b.rbegin()), abs(*a.begin() - *b.begin()));

	std::cout << ans;
}

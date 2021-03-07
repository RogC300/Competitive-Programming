/*
 * String Reversal.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int t[200000], n;

int sum(int r) {
	int s = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		s += t[r];
	return s;
}

void inc(int i, int d) {
	for (; i < n; i = (i | (i + 1)))
		t[i] += d;
}

int main() {
	long long int inv = 0;
	std::string s, rev;
	std::vector<int> pos_s[26], cnt(26, 0);

	std::cin >> n >> s, rev = s, std::reverse(rev.begin(), rev.end());

	for (int i = 0; i < (int) s.length(); i++)
		pos_s[s[i] - 'a'].push_back(i);

	for (int i = 0, pot, rev_l; i < (int) s.length(); i++) {
		rev_l = rev[i] - 'a', pot = pos_s[rev_l][cnt[rev_l]];
		inv += (pot - i + sum(n - 1) - sum(pot - 1));
		inc(pot, 1), cnt[rev_l]++;
	}
	std::cout << inv;
}

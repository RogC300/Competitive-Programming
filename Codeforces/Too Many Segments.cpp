/*
 * Too Many Segments.cpp
 */
#include <iostream>
#include <vector>
#include <set>

#define N 200005

int main() {
	int n, k, cur_sub = 0, u = 0;
	std::vector<int> cnt(N, 0), sub(N, 0);
	std::vector<std::vector<int>> loc(N);
	std::vector<std::pair<int, int>> seg;
	std::set<std::pair<int, int>> cur_seg;
	std::vector<bool> used(N, false);

	std::cin >> n >> k;
	for (int i = 0, l, r; i < n; i++) {
		std::cin >> l >> r, cnt[l]++, cnt[r + 1]--;
		loc[l].push_back(i + 1), loc[r + 1].push_back(-i - 1);
		seg.push_back( { l, r });
	}
	for (int i = 0; i + 1 < N; i++)
		cnt[i + 1] += cnt[i];

	for (int i = 0, pos; i < N; i++) {
		cur_sub += sub[i];
		for (auto it : loc[i])
			if (it > 0)
				cur_seg.insert( { seg[it - 1].second, it - 1 });
			else
				cur_seg.erase( { seg[-it - 1].second, -it - 1 });

		while (cnt[i] - cur_sub > k) {
			pos = cur_seg.rbegin()->second, used[pos] = true, u++;
			cur_seg.erase(prev(cur_seg.end()));
			cur_sub++, sub[seg[pos].second + 1]--;
		}
	}
	std::cout << u << "\n";
	for (int i = 0; i < n; i++)
		if (used[i])
			std::cout << i + 1 << " ";
}

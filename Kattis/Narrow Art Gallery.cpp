/*
 * Narrow Art Gallery.cpp
 */
#include <iostream>
#include <vector>
#include <map>

struct state {
	int pos;
	int need;
	bool prevl;
	bool prevr;
};

bool operator<(state a, state b) {
	return std::tie(a.pos, a.need, a.prevl, a.prevr)
			< std::tie(b.pos, b.need, b.prevl, b.prevr);
}

int n;
std::vector<std::pair<int, int>> g;
std::map<state, int> memo;

int recurse(state c) {
	if (memo.count(c) > 0)
		return memo[c];

	int l = g[c.pos].first, r = g[c.pos].second, ans = -1e9;

	if (c.pos == n) {
		if (c.need == 0)
			return 0;
		return -1e9;
	}

	if (c.need == 0) {
		state next = { c.pos + 1, 0, true, true };
		ans = l + r + recurse(next);
		return ans;
	}

	if (c.prevl) {
		state next = { c.pos + 1, c.need - 1, true, false };
		ans = std::max(ans, l + recurse(next));
	}

	if (c.prevr) {
		state next = { c.pos + 1, c.need - 1, false, true };
		ans = std::max(ans, r + recurse(next));
	}

	state next = { c.pos + 1, c.need, true, true };
	ans = std::max(ans, r + l + recurse(next));

	memo[c] = ans;
	return ans;
}

int main() {
	int need;
	while (std::cin >> n >> need && n != 0) {
		memo.clear(), g.resize(n);
		for (auto &i : g)
			std::cin >> i.first >> i.second;

		state starts = { 0, need, true, true };
		std::cout << recurse(starts) << "\n";
	}
}

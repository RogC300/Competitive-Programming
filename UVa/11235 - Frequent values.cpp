/*
 * 11235 - Frequent values.cpp
 */
#include <iostream>
#include <map>
#include <cstring>

int input[100005], tree[4 * 100005], cnt[100005], start[100005];
std::map<int, int> map;

void build(int node, int low, int high) {
	if (low == high)
		tree[node] = cnt[low];
	else {
		int mid = (low + high) / 2;
		build(node * 2, low, mid);
		build(node * 2 + 1, mid + 1, high);
		tree[node] = std::max(tree[node * 2], tree[node * 2 + 1]);
	}
}

int query(int v, int low, int high, int qlow, int qhigh) {
	if (low > qhigh || high < qlow)
		return -100000008;
	else if (low >= qlow && high <= qhigh)
		return tree[v];
	int mid = (low + high) / 2;
	int l = query(v * 2, low, mid, qlow, qhigh);
	int r = query(v * 2 + 1, mid + 1, high, qlow, qhigh);
	return std::max(l, r);
}

int main() {
	int n, q;
	while (scanf("%d", &n) == 1 && n != 0) {
		scanf("%d", &q);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &input[i]);
			map[input[i]]++;
		}
		int y = -100000008, k;
		for (int i = 1; i <= n; i++) {
			int x = map[input[i]];
			cnt[i] = x;
			if (input[i] != y)
				k = i, y = input[i];
			start[i] = k;
		}
		build(1, 1, n);
		for (int i = 1; i <= q; i++) {
			int qlow, qhigh, cnt1, cnt2, cnt3;
			scanf("%d %d", &qlow, &qhigh);
			if (input[qlow] != input[qhigh]) {
				int end = start[qlow] + cnt[qlow];
				cnt1 = start[qlow] + cnt[qlow] - qlow;
				cnt2 = qhigh - start[qhigh] + 1;
				cnt3 = query(1, 1, n, end, start[qhigh] - 1);
				printf("%d\n",
						std::max(cnt1, cnt2) > std::max(cnt2, cnt3) ?
								std::max(cnt1, cnt2) : std::max(cnt2, cnt3));
			} else
				printf("%d\n", qhigh - qlow + 1);
		}
		memset(tree, 0, sizeof(tree));
		memset(cnt, 0, sizeof(cnt));
		memset(start, 0, sizeof(start));
		map.clear();
	}
}

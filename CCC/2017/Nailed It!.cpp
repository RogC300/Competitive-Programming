/*
 * Nailed It!.cpp
 */
#include <iostream>
#include <vector>

std::vector<int> m(4005, 0);

int find_h(int h) {
	int cnt = 0, i = 1, j = h - 1;

	while (i < j)
		cnt += std::min(m[i++], m[j--]);
	if (i == j)
		cnt += m[i] / 2;

	return cnt;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int n, mx_l = 1, mx_cnt = 0;

	std::cin >> n;

	for (int i = 0, in; i < n; i++)
		std::cin >> in, m[in]++;

	for (int i = 2, cnt; i <= 4000; i++) {
		cnt = find_h(i);
		if (cnt == mx_l)
			mx_cnt++;
		if (cnt > mx_l)
			mx_l = cnt, mx_cnt = 1;
	}
	std::cout << mx_l << " " << mx_cnt;
}

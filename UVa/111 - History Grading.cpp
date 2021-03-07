/*
 * 111 - History Grading.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

const int INF = 1e9;

int lis(std::vector<int> a) {
	int n = a.size(), lis = 0;
	std::vector<int> d(n + 1, INF);
	d[0] = -INF;

	for (int i = 0; i < n; i++) {
		int j = std::upper_bound(d.begin(), d.end(), a[i]) - d.begin();
		if (d[j - 1] < a[i] && a[i] < d[j])
			d[j] = a[i];
	}

	for (int i = 0; i <= n; i++)
		if (d[i] < INF)
			lis = i;
	return lis;
}

void print_v(std::vector<int> v) {
	for (int i = 0; i < (int) v.size(); i++)
		std::cout << v[i] << (i == (int) v.size() - 1 ? "\n" : " ");
	puts("");
}

int main() {
	int n, tmp;
	std::vector<int> list, order;
	std::cin >> n;
	list.resize(n), order.resize(n);
	for (int i = 0; i < n; i++)
		std::cin >> order[i], order[i] -= 1;

	while (std::cin >> tmp) {
		list.clear(), list.resize(n), list[tmp - 1] = order[0];
		for (int i = 1, rank; i < n; i++)
			std::cin >> rank, list[rank - 1] = order[i];
		printf("%d\n", lis(list));
	}
}

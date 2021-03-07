/*
 * 481 - What Goes Up.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1e9;

void lis(std::vector<int> a) {
	int n = a.size(), ans;
	std::vector<int> d(n + 1, INF), tail(n, -1), p(n);
	d[0] = -INF;

	for (int i = 0; i < n; i++) {
		int j = std::upper_bound(d.begin(), d.end(), a[i]) - d.begin();
		if (d[j - 1] < a[i] && a[i] < d[j])
			d[j] = a[i], tail[j] = i, p[i] = tail[j - 1];
	}
	for (int i = 0; i < (int) d.size(); i++)
		if (d[i] < INF)
			ans = i;
	printf("%d\n-\n", ans);

	std::vector<int> out;
	for (int i = tail[ans]; i >= 0; i = p[i])
		out.push_back(a[i]);
	std::reverse(out.begin(), out.end());
	for (int i = 0; i < ans; i++)
		std::cout << out[i] << "\n";

}

int main() {
	int num;
	std::vector<int> a;
	while (std::cin >> num)
		a.push_back(num);
	lis(a);
}

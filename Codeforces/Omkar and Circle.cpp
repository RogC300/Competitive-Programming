/*
 * Omkar and Circle.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int n, max;
	long long int cur, ans;
	std::vector<int> v, alt;

	std::cin >> n, v.resize(n), max = (n + 1) / 2;

	for (int i = 0; i < n; i++)
		std::cin >> v[i];

	cur = ans = 0;
	for (int i = 0; i < max; i++)
		cur += v[i * 2], alt.push_back(v[i * 2]);
	for (int i = 1; i < max; i++)
		alt.push_back(v[i * 2 - 1]);

	int s = alt.size();
	for (int i = 0; i < s; i++)
		alt.push_back(alt[i]);

	for (int i = max; i < (int) alt.size(); i++)
		cur += alt[i], cur -= alt[i - max], ans = std::max(ans, cur);

	std::cout << ans;
}

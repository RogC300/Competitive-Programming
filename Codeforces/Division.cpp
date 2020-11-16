/*
 * Division.cpp
 */
#include <iostream>
#include <vector>

void solve() {
	long long int p, q, ans, temp;
	std::cin >> p >> q;
	std::vector<int> factors, powers;

	if (p % q != 0) {
		std::cout << p << "\n";
		return;
	}
	temp = q;

	for (long long int i = 2, pow; i * i <= q; i++)
		if (temp % i == 0) {
			factors.push_back(i), pow = 0;
			while (temp % i == 0)
				temp /= i, pow++;
			powers.push_back(pow);
		}
	if (temp > 1)
		factors.push_back(temp), powers.push_back(1);

	long long int min = 1, t_p;
	ans = p;

	for (int i = 0, cnt_p; i < (int) factors.size(); i++) {
		cnt_p = 0, t_p = p, min = 1;

		while (t_p % factors[i] == 0)
			cnt_p++, t_p /= factors[i];

		while (cnt_p >= powers[i])
			min *= factors[i], cnt_p--;
		ans = std::min(min, ans);
	}
	std::cout << p / ans << "\n";
}

int main() {
	int t = 1;
	std::cin >> t;
	while (t--)
		solve();
}

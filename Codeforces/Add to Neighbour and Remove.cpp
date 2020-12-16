/*
 * Add to Neighbour and Remove.cpp
 */
#include <iostream>
#include <vector>

std::vector<int> v;

bool check(int s) {
	for (int i = 0, temp = 0; i < (int) v.size(); i++) {
		temp += v[i];
		if (temp == s)
			temp = 0;
		if (temp > s)
			return false;
	}
	return true;
}

void solve() {
	int n, sum = 0;
	std::cin >> n, v.resize(n);

	for (int i = 0; i < n; i++)
		std::cin >> v[i], sum += v[i];

	for (int i = n; i > 0; i--)
		if (sum % i == 0 && check(sum / i)) {
			std::cout << n - i << "\n";
			break;
		}
}

int main() {
	int tc;

	std::cin >> tc;

	while (tc--)
		solve();
}

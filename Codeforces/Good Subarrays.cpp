/*
 * Good Subarrays.cpp
 */
#include <iostream>
#include <vector>
#include <map>

int main() {
	int n, tc;
	long long int ans;
	char in;
	std::vector<int> v;
	std::map<int, int> m;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n, ans = 0, v.clear(), m.clear(), m[0] = 1;
		for (int i = 0; i < n; i++)
			std::cin >> in, v.push_back(in - '0');

		for (int i = 0, cons_sum = 0; i < n; i++) {
			cons_sum += v[i];
			m[cons_sum - i - 1]++;
			ans += m[cons_sum - i - 1] - 1;
		}
		std::cout << ans << "\n";
	}
}

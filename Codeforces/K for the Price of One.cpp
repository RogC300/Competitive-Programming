/*
 * K for the Price of One.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int num_goods, coins, deal, ans, tc;
	std::vector<int> prices;

	std::cin >> tc;

	while (tc--) {
		std::cin >> num_goods >> coins >> deal;
		prices.clear(), ans = 0;

		for (int i = 0, p; i < num_goods; i++)
			std::cin >> p, prices.push_back(p);
		std::sort(prices.begin(), prices.end());

		for (int i = 0, bal, cnt, sub = 0; i < deal; i++) {
			sub = i > 0 ? sub + prices[i - 1] : sub;
			bal = coins - sub, cnt = i > 0 ? i : 0;

			if (bal < 0)
				continue;

			for (int j = i + deal - 1; j < num_goods; j += deal)
				if (bal - prices[j] >= 0)
					bal -= prices[j], cnt += deal;
				else
					break;
			ans = std::max(ans, cnt);
		}
		std::cout << ans << "\n";
	}
}

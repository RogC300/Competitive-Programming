/*
 * 11517 - Exact Change.cpp
 */

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
/* Memo version
 std::vector<int> available_coins;
 int cost, min_overpay = 1e9, used, num_available_coins;
 bool dp[10001], used_coins[101];

 void num_coins(int count, int amount) {
 if (amount >= cost) {
 if (amount < min_overpay || (amount == min_overpay && count < used))
 min_overpay = amount, used = count;
 return;
 }
 if (dp[amount])
 return;
 dp[amount] = true;

 for (int i = 0; i < num_available_coins; i++)
 if (!used_coins[i]) {
 used_coins[i] = true;
 num_coins(count + 1, amount + available_coins[i]);
 used_coins[i] = false;
 }
 }
 void print_v(std::vector<int> v) {
 for (int i = 0; i < (int) v.size(); i++)
 std::cout << v[i] << (i == (int) v.size() - 1 ? "\n" : " ");
 puts("");
 }
 int main() {
 int tc;
 std::cin >> tc;
 while (tc--) {
 available_coins.clear(), min_overpay = 1e9;
 std::cin >> cost >> num_available_coins;
 for (int i = 0, coin; i < num_available_coins; i++)
 std::cin >> coin, available_coins.push_back(coin);
 std::sort(available_coins.rbegin(), available_coins.rend());
 memset(dp, false, sizeof dp), memset(used_coins, false,
 sizeof used_coins);
 num_coins(0, 0);
 std::cout << min_overpay << " " << used << "\n";
 //		print_v(available_coins);
 }
 }
 */
// tabulated version
#include <iostream>

int main() {
	int tc;
	std::cin >> tc;
	while (tc--) {
		std::vector<int> c;
		int num_c, target;
		std::cin >> target >> num_c;
		int dp[30001];
		for (int i = 0, temp; i < num_c; i++)
			std::cin >> temp, c.push_back(temp);
		dp[0] = 0;
		for (int i = 1; i <= 30000; i++)
			dp[i] = 1e9;

		for (int i = 0; i < num_c; i++)
			for (int v = 30001 - c[i] - 1; v >= 0; v--)
				if (dp[v] < 1e9)
					dp[v + c[i]] = std::min(dp[v + c[i]], dp[v] + 1);

		for (int i = target; i < 30000; i++)
			if (dp[i] != 1e9) {
				std::cout << i << " " << dp[i] << "\n";
				break;
			}
	}
}

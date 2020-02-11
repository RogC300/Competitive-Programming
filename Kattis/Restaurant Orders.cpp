/*
 * Restaurant Orders.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> menu, dp;
int max = 0;

void coin(int index, int sum) {
	if (sum > max || dp[sum] > 2)
		return;
	dp[sum]++;

	for (int i = index; i < (int) menu.size(); i++)
		coin(i, sum + menu[i]);
}

void pv(std::vector<int> v) {
	for (int i = 0; i < (int) v.size(); i++)
		std::cout << v[i] << (i == (int) v.size() - 1 ? "\n" : " ");
	puts("");
}

int main() {
	int n_items, num_orders;
	std::vector<int> orders;

	std::cin >> n_items, menu.resize(n_items);
	for (int i = 0; i < n_items; i++)
		std::cin >> menu[i];
	std::cin >> num_orders, orders.resize(num_orders);
	for (int i = 0; i < num_orders; i++)
		std::cin >> orders[i], max = std::max(orders[i], max);
	dp.assign(max + 1, 0);

	coin(0, 0);
//	pv (dp);
	for (auto i : orders)
		if (dp[i] == 1) {
			int targ = i;
			std::vector<int> bought;
			for (int j = n_items - 1; j >= 0; j--)
				while (targ - menu[j] >= 0 && dp[targ - menu[j]] == 1)
					targ -= menu[j], bought.push_back(j);
			std::reverse(bought.begin(), bought.end());
			for (auto j : bought)
				std::cout << j + 1 << " ";
			std::cout << "\n";
		} else if (dp[i] == 0)
			std::cout << "Impossible\n";
		else
			std::cout << "Ambiguous\n";
}

/*
 * 10684 - The jackpot.cpp
 */
#include <iostream>

int main() {
	int num_bets;
	while (std::cin >> num_bets && num_bets != 0) {
		int max = 0, tmp_money = 0;
		for (int i = 0, bet = 0; i < num_bets; i++) {
			std::cin >> bet;
			tmp_money += bet;
			max = std::max(tmp_money, max);
			if (tmp_money < 0)
				tmp_money = 0;
		}
		if (max > 0)
			printf("The maximum winning streak is %d.\n", max);
		else
			puts("Losing streak.");
	}
}

/*
 * Bachet's Game.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>

int main() {
	int numOfStones, numOfMoves;
	bool dp[1000001];

	while (scanf("%d %d", &numOfStones, &numOfMoves) == 2) {
		std::vector <int> move(numOfMoves);
		for (int i = 0; i < numOfMoves; i++)
			scanf("%d", &move[i]);
		dp[0] = false;
		for (int i = 1; i <= numOfStones; i++) {
			dp[i] = false;
			for (int j = 0; j < numOfMoves; j++)
				if (i >= move[j] && !dp[i - move[j]]) {
					dp[i] = true;
					break;
				}
		}

		if (dp[numOfStones])
			printf("Stan wins\n");
		else
			printf("Ollie wins\n");
	}
}


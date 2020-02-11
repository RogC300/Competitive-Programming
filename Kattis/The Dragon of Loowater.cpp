/*
 * The Dragon of Loowater.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	while (true) {
		int numOfHeads, numOfKnights, coins = 0;
		bool ok = true;
		scanf("%d %d", &numOfHeads, &numOfKnights);
		std::vector<int> heads(numOfHeads), knights(numOfKnights);

		if (numOfHeads == 0 && numOfKnights == 0)
			break;
		for (int i = 0; i < numOfHeads; ++i)
			scanf("%d", &heads[i]);
		for (int i = 0; i < numOfKnights; ++i)
			scanf("%d", &knights[i]);

		std::sort(heads.begin(), heads.end());
		std::sort(knights.begin(), knights.end());

		for (int i = 0, j = 0; i < numOfHeads && ok; i++) {
			while (j < numOfKnights && knights[j] < heads[i])
				j++;
			if (j == numOfKnights)
				ok = false;
			else
				coins += knights[j++];
		}

		if (!ok)
			puts("Loowater is doomed!");
		else
			printf("%d\n", coins);
	}
}

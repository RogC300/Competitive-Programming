/*
 * 11559.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main(){
	int participants, budget, hotels, weeks, finalCost, perPersonCost, availableBeds, cap = 0;
	while (scanf ("%d %d %d %d", &participants, &budget, &hotels, &weeks) == 4){
		finalCost = budget+1;
	for (int i = 0; i < hotels; i++){
		scanf ("%d", &perPersonCost);
		for (int j = 0; j < weeks; j++){
			scanf("%d", &availableBeds);
			cap = std::max(availableBeds, cap);
		}
		if (cap >= participants) finalCost = std::min((perPersonCost*participants), finalCost);
	}
	if (finalCost == budget+1)
		printf ("stay home\n");
	else
		printf ("%d\n", finalCost);
	}
}


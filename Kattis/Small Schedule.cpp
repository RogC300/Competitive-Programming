/*
 * Small Schedule.cpp
 *
 *      Author: tempo
 */
#include <iostream>

int main() {
	int longBatchTime, machinesOwned, oneSecPurchase, longBatchPurchase;
	std::cin >> longBatchTime >> machinesOwned >> oneSecPurchase
			>> longBatchPurchase;
	int r, numOfQ, numOfOne = 0;

	r = longBatchPurchase % machinesOwned;
	if (r > 0) {
		numOfQ = (longBatchPurchase / machinesOwned) + 1;
		if ((double) oneSecPurchase / (double) (machinesOwned - r)
				> longBatchTime) {
			oneSecPurchase = oneSecPurchase
					- ((machinesOwned - r) * longBatchTime);
			if (oneSecPurchase % machinesOwned > 0)
				numOfOne = (oneSecPurchase / machinesOwned) + 1;
			else
				numOfOne = oneSecPurchase / machinesOwned;
			std::cout << numOfOne + numOfQ * longBatchTime;
		} else
			std::cout << numOfQ * longBatchTime;
	} else {
		numOfQ = longBatchPurchase / machinesOwned;

		if (oneSecPurchase % machinesOwned > 0)
			numOfOne = (oneSecPurchase / machinesOwned) + 1;
		else
			numOfOne = oneSecPurchase / machinesOwned;
		std::cout << numOfOne + numOfQ * longBatchTime;
	}
}

/*
 * 10114.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <cmath>

int main(){
	while (true){
	int months, depreciatingRecords, answer = 1;
	double downPayment, loanCost, percentage[100], prevPercent;
	scanf ("%d %lf %lf %d", &months, &downPayment, &loanCost, &depreciatingRecords);
	if (months <= 0)
		break;
	double carCost = downPayment + loanCost;
	downPayment = loanCost / months;
	for (int i = 0; i < 100; i++)
		percentage[i] = 0;
	for (int i = 0; i < depreciatingRecords; i++){
		int monthNum;
		double percent;
		scanf ("%d %lf", &monthNum, &percent);
		percentage[monthNum] = percent;
	}


	if (percentage[0] != 0) prevPercent = percentage[0];
//	printf("%lf\n", prevPercent);
	carCost = carCost*(1-prevPercent);
//	printf ("%lf %lf\n", carCost, loanCost);
	if (loanCost < carCost)
		answer = 0;
	else {
	for (int i = 1; i <= months; i++){
		if (percentage[i] != 0) prevPercent = percentage[i];
	//	printf("%lf\n", prevPercent);
		carCost = carCost*(1-prevPercent);
		loanCost -= downPayment;
	//	printf ("%lf %lf\n", carCost, loanCost);
		if (loanCost < carCost) {
			answer = i;
			break;
		}
	}
}
	printf ("%d", answer);
	if (answer != 1) printf(" months\n");
	else printf(" month\n");
	}
}


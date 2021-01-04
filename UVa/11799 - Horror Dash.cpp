/*
 * 11799.cpp
 *
 *      Author: tempo
 */
#include <iostream>

int main(){
	int runs, students, lowestSpeed = 0, compare, caseNumber = 1;
	scanf ("%d", &runs);

	for (int i = 0; i < runs; i++){
		lowestSpeed = 0;
		scanf("%d", &students);
		for (int j = 0; j < students; j++){
			scanf("%d", &compare);
			lowestSpeed = std::max(compare, lowestSpeed);
		}
		printf("Case %d: %d\n", caseNumber, lowestSpeed);
		caseNumber++;
	}
}

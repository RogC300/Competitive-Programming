/*
 * 12356 - Army Buddies.cpp
 *
 *      Author: tempo
 */
#include <iostream>

int numOfSoldiers, numOfCommands, L, R;
int LS[1000100], RS[1000100];

int main() {
	for (;;) {
		scanf("%d %d", &numOfSoldiers, &numOfCommands);
		if (numOfSoldiers == 0 && numOfCommands == 0)
			break;
		for (int i = 0; i < numOfSoldiers + 1; i++) {
			LS[i] = i - 1;
			RS[i] = i + 1;
		}
		for (int i = 0; i < numOfCommands; i++) {
			scanf("%d %d", &L, &R);
			if (LS[L] < 1)
				printf("* ");
			else
				printf("%d ", LS[L]);
			if (RS[R] > numOfSoldiers)
				printf("*\n");
			else
				printf("%d\n", RS[R]);

			LS[RS[R]] = LS[L];
			RS[LS[L]] = RS[R];
		}
		printf("-\n");
	}
}

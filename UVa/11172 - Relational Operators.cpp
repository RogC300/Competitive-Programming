/*
 * 11172.cpp
 *
 *      Author: tempo
 */
#include <iostream>

int main(){
	int runs;
	int A, B;
	scanf("%i", &runs);
	for (int i = 0; i < runs; i++){
		scanf("%i %i", &A, &B);
		if (A > B)
			printf(">\n");
		else if (A < B)
			printf("<\n");
		else
			printf("=\n");
	}
}




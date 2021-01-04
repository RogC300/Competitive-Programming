/*
 * 543 - Goldbach's Conjecture.cpp
 */
#include <iostream>
#include <string.h>

#define MAX 1000001

bool sieve[MAX];
void create_sieve() {
	memset(sieve, true, sizeof sieve);
	sieve[0] = sieve[1] = false;

	for (int i = 2; i * i < MAX; i++)
		if (sieve[i] == true)
			for (int j = i * i; j < MAX; j += i)
				sieve[j] = false;
}

int main() {
	create_sieve();
	bool found;
	int n, t1, t2;

	while (std::cin >> n && n != 0) {
		found = false, t1 = n - 2, t2 = 2;
		while (t1-- && t2++ && t1 >= t2)
			if (sieve[t1] && sieve[t2]) {
				found = true;
				break;
			}
		if (found)
			printf("%d = %d + %d\n", n, t2, t1);
		else
			puts("Goldbach's conjecture is wrong.");
	}
}

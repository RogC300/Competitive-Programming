/*
 * Collatz Conjecture.cpp
 */
#include <iostream>

int main() {
	long long int * aa;
	long long int a, b;
	while (std::cin >> a >> b && a && b) {
		int count = 0, tempa = a, tempb = b, index = 1;
		bool found = false;

		aa = new long long int[1000];
		aa[0] = a;
		while (a != 1)
			a % 2 == 0 ? a /= 2 : a = a * 3 + 1, aa[index] = a, index++;

		while (!found) {
			for (int j = 0; j < index; j++)
				if (aa[j] == b) {
					printf(
							"%d needs %d steps, %d needs %d steps, they meet at %d\n",
							tempa, j, tempb, count, aa[j]);
					found = true;
					break;
				}
			b % 2 == 0 ? b /= 2 : b = b * 3 + 1;
			count++;
		}
	}
}

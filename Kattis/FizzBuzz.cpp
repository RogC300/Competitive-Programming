/*
 * FizzBuzz.cpp
 */
#include <iostream>

int main() {
	int x, y, n;
	std::cin >> x >> y >> n;
	for (int i = 1; i <= n; i++)
		if (i % x == 0 && i % y == 0)
			puts("FizzBuzz");
		else if (i % x == 0)
			puts("Fizz");
		else if (i % y == 0)
			puts("Buzz");
		else
			printf("%d\n", i);
}

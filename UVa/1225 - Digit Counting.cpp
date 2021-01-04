/*
 * 1225 - Digit Counting.cpp
 */
#include <iostream>
#include <string.h>

int count[10];

void add_to_count(int n) {
	int x;
	while (n != 0) {
		x = n % 10;
		count[x]++;
		n /= 10;
	}
}

int main() {
	int tc;
	std::cin >> tc;
	while (tc--) {
		int n;
		std::cin >> n;
		memset(count, 0, sizeof count);
		for (int i = 1; i <= n; i++)
			add_to_count(i);
		for (int i = 0; i < 10; i++)
			std::cout << count[i] << (i == 9 ? "\n" : " ");
	}
}

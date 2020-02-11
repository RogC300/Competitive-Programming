/*
 * Batmanacci.cpp
 */
#include <iostream>

long long len[100100];

char get(long long n, long long k) {
	if (n == 1)
		return 'N';
	else if (n == 2)
		return 'A';

	if (k <= len[n - 2])
		return get(n - 2, k);
	else
		return get(n - 1, k - len[n - 2]);
}

int main() {
	len[1] = 1, len[2] = 1;
	for (int i = 3; i < 100100; i++) {
		len[i] = len[i - 2] + len[i - 1];
		if (len[i] > 1000000000000000000)
			len[i] = 1000000000000000001;
	}

	long long n, k;
	std::cin >> n >> k;

	std::cout << get(n, k) << std::endl;
}

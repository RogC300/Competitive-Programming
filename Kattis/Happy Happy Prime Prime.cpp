/*
 * Happy Happy Prime Prime.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool isPrime(int n) {
	if (n % 2 == 0)
		return false;
	for (int i = 3; i <= sqrt(n); i += 2)
		if (n % i == 0)
			return false;
	return true;
}

std::vector<int> toArray(int n) {
	std::vector<int> num;
	while (n != 0) {
		int temp = n % 10;
		num.push_back(temp);
		n /= 10;
	}
	return num;
}

bool isHappyPrime(int n) {
	if (n == 1)
		return false;
	std::vector<int> previousNumbers;
	while (true) {
		std::vector<int> num = toArray(n);
		int x = 0;

		for (unsigned int i = 0; i < num.size(); i++)
			x += num[i] * num[i];

		if (x == 1)
			return true;

		for (unsigned int i = 0; i < previousNumbers.size(); i++)
			if (x == previousNumbers[i])
				return false;

		previousNumbers.push_back(x);
		n = x;
	}
}

int main() {
	int runs, temp, n;
	std::cin >> runs;
	for (int i = 0; i < runs; i++) {
		std::cin >> temp >> n;
		if (isHappyPrime(n) && isPrime(n))
			printf("%d %d YES\n", temp, n);
		else
			printf("%d %d NO\n", temp, n);
	}
}

/*
 * Cyclic Permutations.cpp
 */
#include <iostream>

int mod = 1e9 + 7;

int main() {
	int n;

	std::cin >> n;

	long long int fact = 1, pow_2 = 2;
	for (int i = 1; i < n; i++)
		fact *= i, fact %= mod;
	fact *= n;
	for (int i = 2; i < n; i++)
		pow_2 *= 2, pow_2 %= mod;
	std::cout << (fact - pow_2) % mod;
}

/*
 Finding the solution was a little bit tedious, all
 you had to do was figure out the solution for n = 3, 5 and 6
 (4 is given) and compare it to the total possible permutations.
 This gives the solution being making sure it is always increasing
 or decreasing all the way through (just make it a hill) and finding
 the number of permuations that don't work to be 4, 8, 16, 32 for n =
 3, 4, 5, 6.
 */

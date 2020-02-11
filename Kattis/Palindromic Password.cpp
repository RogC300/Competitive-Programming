/*
 * Palindromic Password.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>
#include <cmath>

bool ispalindrome(int i) {
	std::string s = std::to_string(i);
	return ((s[0] == s[5]) && (s[1] == s[4]) && (s[2] == s[3]));
}

int solve(std::vector<bool>& memo, int i) {
	int j = 0, k = 0;
	for (j = i; j >= 0; j--)
		if (memo[j])
			break;
	for (k = i; k <= 999999; k++)
		if (memo[k])
			break;

	int diff1 = abs(j - i), diff2 = abs(k - i);
	if (diff1 <= diff2)
		return j;
	else
		return k;
}

void build(std::vector<bool>& memo) {
	for (int i = 0; i <= 1000000; i++)
		if (ispalindrome(i))
			memo[i] = true;
}

int main() {
	int cases, password;
	std::vector<bool> memo(1000002, false);
	std::cin >> cases;
	build(memo);
	while (cases--) {
		std::cin >> password;
		std::cout << solve(memo, password) << std::endl;
	}
}

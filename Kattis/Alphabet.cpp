/*
 * Alphabet.cpp
 *
 *      Author: tempo
 */
#include<iostream>
#include<string>
#include<algorithm>
// Longest Common Subsequence Dynamic Programming
void findLCSLength(std::string X, std::string Y, int XLen, int YLen) {
	int L[XLen + 1][YLen + 1];

	for (int r = 0; r <= XLen; r++)
		for (int c = 0; c <= YLen; c++)
			if (r == 0 || c == 0)
				L[r][c] = 0;
			else if (X[r - 1] == Y[c - 1])
				L[r][c] = L[r - 1][c - 1] + 1;
			else
				L[r][c] = std::max(L[r - 1][c], L[r][c - 1]);

	printf("%d", 26 - L[XLen][YLen]);
}

int main() {
	std::string X("abcdefghijklmnopqrstuvwxyz"), Y;
	std::cin >> Y;

	int XLen = X.length();
	int YLen = Y.length();

	findLCSLength(X, Y, XLen, YLen);
}

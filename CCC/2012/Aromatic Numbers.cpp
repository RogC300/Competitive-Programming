/*
 * Aromatic Numbers.cpp
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
	std::string in;
	int sum = 0;
	map<char, int> m = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, {
			'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
	std::cin >> in;

	for (int i = 0, cur; i < (int) in.length(); i += 2) {
		cur = (in[i] - '0') * m[in[i + 1]];
		if (i + 3 < (int) in.length() && m[in[i + 3]] > m[in[i + 1]])
			cur = -cur;
		sum += cur;
	}
	std::cout << sum;
}

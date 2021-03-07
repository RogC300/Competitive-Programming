/*
 * 941 - Permutations.cpp
 */
#include <iostream>
#include <algorithm>

typedef long long int ll;

ll factorial[20];

void compute_factorials() {
	factorial[0] = 1;
	for (int i = 1; i < 20; i++)
		factorial[i] = i * factorial[i - 1];

}

std::string nPermute(std::string str, ll n) {
	n++;
	int freq[26] = { 0 };
	ll sum = 0, xsum;
	std::string out;

	for (int i = 0; i < (int) str.length(); i++)
		freq[str[i] - 'a']++;

	while (sum != n) {
		sum = 0;
		for (int i = 0; i < 26; i++) {
			if (freq[i] == 0)
				continue;
			freq[i]--, xsum = factorial[str.length() - 1 - out.length()];
			for (int j = 0; j < 26; j++)
				xsum /= factorial[freq[j]];
			sum += xsum;

			if (sum >= n) {
				out += i + 'a';
				n -= sum - xsum;
				break;
			}
			freq[i]++;
		}
	}
	for (int i = 25; i >= 0; i--)
		if (freq[i])
			out += i + 'a', freq[i++]--;
	return out;
}

int main() {
	compute_factorials();

	std::string input;
	ll rank, tc;


	std::cin >> tc;

	while (tc--) {
		std::cin >> input >> rank;
		std::cout << nPermute(input, rank) << "\n";
	}
}

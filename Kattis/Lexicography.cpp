/*
 * Lexicography.cpp
 */
#include <iostream>

typedef long long int ll;

ll fact[20];

void fact_compute() {
	fact[0] = 1;
	for (int i = 1; i < 20; i++)
		fact[i] = i * fact[i - 1];
}

std::string nPermute(std::string s, ll n) {
	int freq[26] = { 0 };
	ll sum = 0, xsum;
	std::string out;

	for (int i = 0; i < (int) s.length(); i++)
		freq[s[i] - 'A']++;

	while (sum != n) {
		sum = 0;
		for (int i = 0; i < 26; i++) {
			if (freq[i] == 0)
				continue;
			freq[i]--, xsum = fact[s.length() - 1 - out.length()];

			for (int i = 0; i < 26; i++)
				xsum /= fact[freq[i]];
			sum += xsum;

			if (sum >= n) {
				out += i + 'A', n -= sum - xsum;
				break;
			}
			freq[i]++;
		}
	}
	for (int i = 25; i >= 0; i--)
		if (freq[i])
			out += i + 'A', freq[i++]--;
	return out;
}

int main() {
	fact_compute();
	std::string s;
	ll r;

	while (std::cin >> s >> r && (s != "#" || r != 0))
		std::cout << nPermute(s, r) << "\n";
}

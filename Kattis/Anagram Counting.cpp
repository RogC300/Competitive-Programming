/*
 * Anagram Counting.cpp
 */
#include <iostream>
#include <map>
#include <vector>

struct bigint {
	std::vector<int> n;
	const int base = 10;

	bigint() {
		n.push_back(1);
	}

	void operator*=(int v) {
		long long int cur;
		for (int i = 0, carry = 0; i < (int) n.size() || carry; ++i) {
			if (i == (int) n.size())
				n.push_back(0);
			cur = n[i] * (long long) v + carry;
			carry = cur / base, n[i] = cur % base;
		}
		while (!n.empty() && !n.back())
			n.pop_back();
	}

	void operator/=(int v) {
		long long int cur;
		for (int i = (int) n.size() - 1, rem = 0; i >= 0; i--) {
			cur = n[i] + rem * base;
			n[i] = cur / v, rem = cur % v;
		}
		while (!n.empty() && !n.back())
			n.pop_back();
	}

	void out() {
		for (int i = (int) n.size() - 1; i >= 0; i--)
			std::cout << n[i];
		std::cout << "\n";
	}

	void reset() {
		n.clear();
		n.push_back(1);
	}
};

int main() {
	std::string input;
	bigint b;
	std::map<char, int> count;

	while (std::cin >> input) {
		count.clear(), b.reset();
		for (int i = 0; i < (int) input.length(); i++)
			count[input[i]]++;
		for (int i = input.length(), d; i >= 2; i--)
			d = i, b *= d;

		for (auto i : count)
			for (int j = 2; j <= i.second; j++)
				b /= j;
		b.out();
	}
}

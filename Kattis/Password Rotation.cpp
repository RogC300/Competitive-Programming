/*
 * Password Rotation.cpp
 */
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>

std::set<long long int> set;

std::vector<long long int> p_pow, s_hash;
int p = 1e6 + 3, p2 = 1e6 + 33, mod = 1e9 + 9;

bool hash(std::string s) {
	long long int h = 0;
	int length = s.length();
	h ^= (p * s[length - 1]) + (p2 * s[0]);

	for (int i = 1; i < length; i++)
		h ^= (p * s[i - 1]) + (p2 * s[i]);


	if (set.count(h))
		return true;
	set.insert(h);
//	std::cout << h << "\n";
	return false;
}

int main() {
	long long int n;
	std::string in;
	std::cin >> n;

	bool yes = false;
	for (int i = 0; i < n; i++) {
		std::cin >> in;
		if (yes)
			continue;

		if (hash(in))
			yes = true;
		std::reverse(in.begin(), in.end());
		if (hash(in))
			yes = true;
	}

	if (yes)
		std::cout << "Yes";
	else
		std::cout << "No";
}


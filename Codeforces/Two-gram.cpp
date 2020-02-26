/*
 * Two-gram.cpp
 */
#include <iostream>
#include <map>

int main() {
	std::string n;
	std::map<std::string, int> m;
	int l;

	std::cin >> l >> n;

	for (int i = 0; i < l - 1; i++)
		m[n.substr(i, 2)]++;
	int max = 0;
	std::string with;
	for (auto i : m)
		if (i.second > max)
			max = i.second, with = i.first;

	std::cout << with;
}

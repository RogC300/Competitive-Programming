/*
 * Assigning Partners.cpp
 */
#include <bits/stdc++.h>

int main() {
	int n;
	std::string in;
	std::vector<std::string> names;
	std::map<std::string, std::string> m;
	bool good = true;

	std::cin >> n, names.resize(n);

	for (int i = 0; i < n; i++)
		std::cin >> names[i];

	for (int i = 0; i < n; i++) {
		std::cin >> in;
		if (m.find(in) != m.end() && m[in] != names[i])
			good = false;
		if (m.find(names[i]) != m.end() && m[names[i]] != in)
			good = false;
		if (names[i] == in)
			good = false;
		m[names[i]] = in, m[in] = names[i];
	}

	std::cout << (good ? "good" : "bad");
}

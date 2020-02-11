/*
 * Incognito.cpp
 */
#include <iostream>
#include <map>

int main() {
	int c;
	std::cin >> c;
	while (c--) {
		int n, sum = 1;
		std::map<std::string, int> m;
		std::cin >> n;
		std::string a, b;
		while (n--) {
			std::cin >> a >> b;
			if (m.find(b) == m.end())
				m[b] = 2;
			else
				m[b]++;
		}
		for (auto& it : m)
			sum *= it.second;
		std::cout << sum - 1 << std::endl;
	}
}

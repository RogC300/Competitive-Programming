/*
 * 902 - Password Search.cpp
 */
#include <iostream>
#include <map>

int main() {
	int n, highest;
	std::string input, max;
	std::map<std::string, int> m;

	while (std::cin >> n >> input) {
		m.clear(), highest = 0;
		for (int i = 0; i < (int) input.length() - n; i++) {
			std::string temp = input.substr(i, n);
			m[temp]++;
			if (m[temp] > highest)
				highest = m[temp], max = temp;

		}
		std::cout << max << "\n";
	}
}

/*
 * Substring Removal Game.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::string in;
	std::vector<int> v;
	int len, sum, tc;

	std::cin >> tc;
	while (tc--) {
		std::cin >> in, len = in.length(), v.clear();

		for (int i = 0, j; i < len; i++)
			if (in[i] == '1') {
				for (j = i; j < len; j++)
					if (in[j] == '0')
						break;
				v.push_back(j - i), i = j;
			}

		std::sort(v.rbegin(), v.rend()), sum = 0;

		for (int i = 0; i < (int) v.size(); i += 2)
			sum += v[i];
		std::cout << sum << "\n";
	}
}

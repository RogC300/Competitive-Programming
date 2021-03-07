/*
 * 12036 - Stable Grid.cpp
 */
#include <iostream>
#include <map>

int main() {
	int n, tc = 1, cases;
	bool possible;
	std::map<int, int> count;

	std::cin >> cases;
	while (cases--) {
		std::cin >> n, count.clear(), possible = true;

		for (int i = 0; i < n; i++)
			for (int j = 0, t; j < n; j++)
				std::cin >> t, count[t]++;

		for (auto i : count)
			if (i.second > n)
				possible = false;

		std::cout << "Case " << tc++ << ": " << (possible ? "yes" : "no")
				<< "\n";
	}
}


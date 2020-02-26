/*
 * New Year Garland.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> v(3);
	int n;
	std::cin >> n;

	while (n--) {
		for (int i = 0; i < 3; i++)
			std::cin >> v[i];
		std::sort(v.begin(), v.end());
		if (v[2] <= v[1] + v[0] + 1)
			std::cout << "Yes";
		else
			std::cout << "No";
		puts("");
	}
}

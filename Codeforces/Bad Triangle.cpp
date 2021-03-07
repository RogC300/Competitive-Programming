/*
 * Bad Triangle.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> v;
	int n, tc;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n, v.resize(n);

		for (int i = 0; i < n; i++)
			std::cin >> v[i];

		if (v[n - 1] >= v[0] + v[1])
			printf("1 2 %d\n", n);
		else
			puts("-1");
	}
}

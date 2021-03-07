/*
 * 10487 - Closest Sums.cpp
 */
#include <iostream>
#include <vector>
#include <cmath>

int main() {
	int n, m, count = 1;
	while (std::cin >> n && n != 0) {
		std::vector<int> num, mul;
		for (int i = 0, x; i < n; i++)
			std::cin >> x, num.push_back(x);
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				mul.push_back(num[i] + num[j]);
		std::cin >> m;
		printf("Case %d:\n", count);
		for (int i = 0, x, closest = mul[0]; i < m; i++) {
			std::cin >> x;
			for (int j = 0; j < (int) mul.size(); j++)
				if (abs(mul[j] - x) < abs(closest - x))
					closest = mul[j];
			printf("Closest sum to %d is %d.\n", x, closest);
		}
		count++;
	}
}

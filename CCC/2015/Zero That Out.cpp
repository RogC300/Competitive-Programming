/*
 * Zero That Out.cpp
 */
#include <bits/stdc++.h>

int main() {
	std::vector<int> v;
	int n, ind = 0, sum = 0;
	std::cin >> n, v.resize(n);

	while (n--) {
		std::cin >> v[ind];
		if (v[ind] == 0)
			ind -= 2;
		ind++;
	}
	for (int i = 0; i < ind; i++)
		sum += v[i];
	std::cout << sum;
}

/*
 * Dr. Evil Underscores.cpp
 */
#include <iostream>
#include <vector>

int recurse(int bit, std::vector<int> &cur) {
	if (bit == -1)
		return 0;
	std::vector<int> a, b;

	for (auto i : cur) {
		if ((i >> bit) & 1)
			a.push_back(i);
		else
			b.push_back(i);
	}
	if (a.size() == 0)
		return recurse(bit - 1, b);
	if (b.size() == 0)
		return recurse(bit - 1, a);
	return std::min(recurse(bit - 1, a), recurse(bit - 1, b)) + (1 << bit);
}

int main() {
	int n;
	std::vector<int> num;

	std::cin >> n, num.resize(n);

	for (auto &i : num)
		std::cin >> i;
	std::cout << recurse(30, num);
}

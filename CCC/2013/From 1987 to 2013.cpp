/*
 * From 1987 to 2013.cpp
 */
#include <iostream>
#include <unordered_set>

std::unordered_set<int> set;

bool unique(int n) {
	std::string s = std::to_string(n);
	set.clear();
	for (auto c : s) {
		if (set.count(c - '0'))
			return false;
		set.insert(c - '0');
	}
	return true;
}

int main() {
	int n;
	std::cin >> n;

	for (n = n + 1;; n++)
		if (unique(n)) {
			std::cout << n;
			break;
		}
}

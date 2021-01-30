/*
 * Gates.cpp
 */
#include <bits/stdc++.h>

int main() {
	std::set<int> airport;
	int gates, planes, cnt = 0;
	bool ok = true;

	std::cin >> gates >> planes;
	for (int i = 0; i < gates; i++)
		airport.insert(i);

	for (int i = 0, g; i < planes; i++) {
		std::cin >> g, g -= 1;

		if (!ok)
			continue;

		auto it = airport.upper_bound(g);

		if (it == airport.begin()) {
			ok = false;
			continue;
		}

		cnt++, airport.erase(--it);
	}
	std::cout << cnt;
}

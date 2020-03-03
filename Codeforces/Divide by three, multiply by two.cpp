/*
 * Divide by three, multiply by two.cpp
 */
#include <iostream>
#include <vector>

int main() {
	std::vector<long long int> a, front, back;
	std::vector<bool> seen;
	int n;

	std::cin >> n, a.resize(n), seen.assign(n, false);
	for (int i = 0; i < n; i++)
		std::cin >> a[i];

	front.push_back(a[0]), seen[0] = true;

	bool cont = true;
	while (cont) {
		cont = false;

		for (int i = 0; i < n; i++) {
			if (seen[i])
				continue;
			if (a[i] == front.back() * 2)
				front.push_back(a[i]), cont = true;
			else if (front.back() % 3 == 0 && front.back() / 3 == a[i])
				front.push_back(a[i]), cont = true;
		}
	}

	back.push_back(a[0]);

	cont = true;
	while (cont) {
		cont = false;

		for (int i = 0; i < n; i++) {
			if (seen[i])
				continue;
			if (a[i] == back.back() * 3)
				back.push_back(a[i]), cont = true;
			else if (back.back() % 2 == 0 && back.back() / 2 == a[i])
				back.push_back(a[i]), cont = true;
		}
	}
	for (int i = back.size() - 1; i > 0; i--)
		std::cout << back[i] << " ";

	for (int i = 0; i < (int) front.size(); i++)
		std::cout << front[i] << " ";
}

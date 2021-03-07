/*
 * Jerseys.cpp
 */
#include <bits/stdc++.h>

bool larger(char a, char b) {
	if (a == b)
		return true;
	if (a == 'L')
		return true;
	if (a == 'M' && b == 'S')
		return true;
	return false;
}

int main() {
	int n, m, cnt = 0;

	std::cin >> n >> m;

	std::vector<char> jerseys(n);
	std::map<int, char> people;

	for (int i = 0; i < n; i++)
		std::cin >> jerseys[i];

	for (int i = 0, num; i < m; i++) {
		char size;
		std::cin >> size >> num;
		if (people.find(num) == people.end() || larger(people[num], size))
			people[num] = size;
	}
//	for (auto i : people)
//		std::cout << i.first << " " << i.second << "\n";

	for (int i = 0; i < n; i++)
		if (people.find(i + 1) != people.end()
				&& larger(jerseys[i], people[i + 1]))
			cnt++;
	std::cout << cnt;
}

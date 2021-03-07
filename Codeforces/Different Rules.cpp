/*
 * Different Rules.cpp
 */
#include <iostream>

int main() {
	int people, r_1, r_2, fin, best, tc;

	std::cin >> tc;

	while (tc--) {
		std::cin >> people >> r_1 >> r_2;
		fin = r_1 + r_2 + 1;
		if (fin - people > 1)
			best = people - (fin - people) + 1;
		else
			best = people;
		std::cout << std::min(people - best + 1, people) << " ";
		if (fin - 1 > people)
			std::cout << people;
		else
			std::cout << std::min(fin - 2, people);
		puts("");
	}
}

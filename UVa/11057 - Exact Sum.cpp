/*
 * 11057 - Exact Sum.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int num_of_books, budget;
	while (std::cin >> num_of_books) {
		std::vector<int> book_costs;
		int p1 = 0, p2 = 1000009;
		for (int i = 0, book; i < num_of_books; i++)
			std::cin >> book, book_costs.push_back(book);
		std::cin >> budget;
		std::sort(book_costs.begin(), book_costs.end());
		for (int i = 0; i < num_of_books; i++)
			if (std::binary_search(book_costs.begin(), book_costs.end(),
					budget - book_costs[i])) {
				if (abs(budget - book_costs[i] - book_costs[i]) < abs(p1 - p2))
					p1 = std::min(budget - book_costs[i], book_costs[i]), p2 =
							std::max(budget - book_costs[i], book_costs[i]);
			}
		printf("Peter should buy books whose prices are %d and %d.\n\n", p1, p2);
	}
}

/*
 * A Prize No One Can Win.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int num_items, max, max_items = -1;
	std::vector<int> items;
	std::cin >> num_items >> max;
	for (int i = 0, item; i < num_items; i++)
		std::cin >> item, items.push_back(item);
	std::sort(items.begin(), items.end());
	for (int i = 0; i < (int) items.size() - 1; i++)
		if ((items[i] + items[i + 1]) > max) {
			max_items = i;
			break;
		}
	if (num_items == 1)
		printf("1");
	else if (max_items == -1)
		std::cout << num_items;
	else
		std::cout << max_items + 1;
}

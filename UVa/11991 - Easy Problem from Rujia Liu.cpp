/*
 * 11991 - Easy Problem from Rujia Liu.cpp
 */
#include <iostream>
#include <vector>

void out(std::vector<std::vector<int>> v) {
	for (int i = 1; i <= (int) v.size(); i++) {
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << v[i][j] << " ";
		std::cout << std::endl;
	}
}

int main() {
	int elements, queries, occurrence, number;
	while (scanf("%d %d", &elements, &queries) != EOF) {
		std::vector<std::vector<int>> v(1000001);
		for (int i = 1, value; i <= elements; i++) {
			scanf("%d", &value);
			v[value].push_back(i);
		}
		for (int i = 0; i < queries; i++) {
			scanf("%d %d", &occurrence, &number);
			if (occurrence - 1 < (int) v[number].size())
				printf("%d\n", v[number][occurrence - 1]);
			else
				printf("0\n");
		}
	}
}

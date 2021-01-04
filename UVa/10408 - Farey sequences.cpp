/*
 * 10408 - Farey sequences.cpp
 */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef std::vector<double> vi;

void pv(std::vector<std::vector<double>> v) {
	for (int i = 0; i < (int) v.size(); i++)
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << v[i][j] << (j == (int) v[i].size() - 1 ? "\n" : " ");
	puts("");
}

int main() {
	std::vector<vi> fractions;
	int n, k;
	std::set<double> set;

	while (std::cin >> n >> k) {
		vi temp;
		fractions.clear();
		set.clear();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j < i; j++) {
				temp.push_back(j), temp.push_back(i);
				double val = (double) j / i;
				temp.push_back(val);
				if (set.count(val) == 0)
					fractions.push_back(temp), set.insert(val);
				temp.clear();
			}
		temp.push_back(1), temp.push_back(1), temp.push_back(1);
		fractions.push_back(temp);

		std::sort(fractions.begin(), fractions.end(), [](vi a, vi b) {
			return a[2] < b[2];
		});

		printf("%.0lf/%.0lf\n", fractions[k - 1][0], fractions[k - 1][1]);
	}
}

/*
 * Medals.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef std::vector<int> vi;

void pv(std::vector<std::vector<int>> v) {
	for (int i = 0; i < (int) v.size(); i++)
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << v[i][j] << (j == (int) v[i].size() - 1 ? "\n" : " ");
	puts("");
}

void input(std::vector<vi> &m, int &num_m, vi &canada, int n) {
	std::string country;
	vi temp(3);
	for (int i = 0; i < n; i++) {
		std::cin >> country >> temp[0] >> temp[1] >> temp[2];
		num_m += temp[0] + temp[1] + temp[2];
		if (country == "Canada")
			canada = temp;
		else
			m.push_back(temp);
	}
}

bool scores(int j, int k, int l, std::vector<vi> m, vi can, int n) {
	j = std::pow(n, j), k = std::pow(n, k), l = std::pow(n, l);
	int can_score = can[0] * j + can[1] * k + can[2] * l;

	for (int i = 0, score; i < (int) m.size(); i++) {
		score = m[i][0] * j + m[i][1] * k + m[i][2] * l;
		if (score > can_score)
			return false;
	}
	return true;
}

bool canada_wins(std::vector<vi> m, int num_m, vi can) {
	if (!can.size())
		return false;
	if (!m.size())
		return true;
	for (int i = 0, less, eq; i < (int) m.size(); i++) {
		less = eq = 0;
		for (int j = 0; j < 3; j++)
			if (can[j] < m[i][j])
				less++;
			else if (can[j] == m[i][j])
				eq++;
		if (less > 0 && less + eq == 3)
			return false;
	}

	for (int k = 0; k < 4; k++)
		for (int j = 0; j < 4; j++)
			for (int l = 0; l < 4; l++)
				if (scores(j, k, l, m, can, num_m))
					return true;
	return false;

}

int main() {
	std::vector<vi> medals;
	vi canada;
	int n, num_medals;

	while (std::cin >> n && n != 0) {
		medals.clear(), canada.clear(), num_medals = 0;
		input(medals, num_medals, canada, n);
		if (canada_wins(medals, num_medals, canada))
			std::cout << "Canada wins!\n";
		else
			std::cout << "Canada cannot win.\n";
//		pv (medals);
	}
}

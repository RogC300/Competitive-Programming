/*
 * 10895 - Matrix Transpose.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int m, n;
	while (scanf ("%d %d", &m, &n) != EOF) {
		m++;
		n++;
		int transpose[n][m];
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++)
				transpose[i][j] = 0;
		}
		for (int i = 1, r; i < m; i++) {
			std::cin >> r;
			std::vector<int> com(r);
			for (int j = 0; j < r; j++)
				std::cin >> com[j];
			for (int j = 0, num; j < r; j++) {
				std::cin >> num;
				transpose[com[j]][i] = num;
			}
		}
		printf ("%d %d\n", n-1, m-1);
		for (int i = 1; i < n; i++) {
			std::vector<int> index, value;
			for (int j = 1; j < m; j++)
				if (transpose[i][j] != 0)
					index.push_back(j), value.push_back(transpose[i][j]);

			printf ("%d", index.size());
			for (int j = 0; j < (int) index.size(); j++)
				printf (" %d", index[j]);
			printf ("\n");

			if (value.size() != 0)
				std::cout << value[0];
			for (int j = 1; j < (int) value.size(); j++)
				printf (" %d", value[j]);
			std::cout << std::endl;
		}
	}
}

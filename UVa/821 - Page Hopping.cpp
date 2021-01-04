/*
 * 821 - Page Hopping.cpp
 */
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
	int a, b, n, tc = 0;
	std::vector<std::vector<int>> matrix;
	while (1) {
		matrix.clear();
		matrix.assign(101, std::vector<int>(101, 1e9));

		n = 0;
		std::cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		matrix[a][b] = 1, n = std::max(n, std::max(a, b));
		while (std::cin >> a >> b && a != 0 && b != 0)
			matrix[a][b] = 1, n = std::max(n, std::max(a, b));

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					matrix[i][j] = std::min(matrix[i][j],
							matrix[i][k] + matrix[k][j]);
		int sum = 0, connections = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (matrix[i][j] < 1e9 && i != j)
					sum += matrix[i][j], connections++;
		printf("Case %d: average length between pages = %.3lf clicks\n", ++tc,
				(double) sum / connections);
	}
}

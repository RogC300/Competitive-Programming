/*
 * 10827 - Maximum sum on a torus.cpp
 */
#include <iostream>

int main() {
	int tc;
	scanf("%d", &tc);
	int n, matrix[75 * 2 + 1][75 * 2 + 1];

	while (tc--) {
		scanf("%d", &n);
		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++) {
				scanf("%d", &matrix[y][x]);
				matrix[y + n][x] = matrix[y][x + n] = matrix[y + n][x + n] =
						matrix[y][x];
			}

		for (int i = 0; i < 2 * n; i++)
			for (int j = 0; j < 2 * n; j++) {
				if (i > 0)
					matrix[i][j] += matrix[i - 1][j];
				if (j > 0)
					matrix[i][j] += matrix[i][j - 1];
				if (i > 0 && j > 0)
					matrix[i][j] -= matrix[i - 1][j - 1];
			}

		int max = 0, sub_rec;
		for (int y1 = 0; y1 < n; y1++)
			for (int x1 = 0; x1 < n; x1++)
				for (int y2 = y1; y2 < n + y1; y2++)
					for (int x2 = x1; x2 < n + x1; x2++) {
						sub_rec = matrix[y2][x2];
						if (y1 > 0)
							sub_rec -= matrix[y1 - 1][x2];
						if (x1 > 0)
							sub_rec -= matrix[y2][x1 - 1];
						if (x1 > 0 && y1 > 0)
							sub_rec += matrix[y1 - 1][x1 - 1];
						max = std::max(sub_rec, max);
					}
		printf("%d\n", max);
	}
}

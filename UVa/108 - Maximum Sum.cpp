/*
 * 108 - Maximum Sum.cpp
 */
#include <iostream>
#include <string.h>

int main() {
	int n, matrix[101][101];
	while (std::cin >> n) {
		memset(matrix, 0, sizeof(matrix));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &matrix[i][j]);
				if (i) // = i > 0
					matrix[i][j] += matrix[i - 1][j];
				if (j)
					matrix[i][j] += matrix[i][j - 1];
				if (i && j)
					matrix[i][j] -= matrix[i - 1][j - 1];
			}
		int max = -127;
		for (int y1 = 0; y1 < n; y1++)
			for (int x1 = 0; x1 < n; x1++)
				for (int y2 = y1; y2 < n; y2++)
					for (int x2 = x1; x2 < n; x2++) {
						int sub_rec = matrix[y2][x2];
						if (y1 > 0)
							sub_rec -= matrix[y1 - 1][x2];
						if (x1 > 0)
							sub_rec -= matrix[y2][x1 - 1];
						if (y1 > 0 && x1 > 0)
							sub_rec += matrix[y1 - 1][x1 - 1];
						max = std::max(sub_rec, max);
					}
		printf("%d\n", max);
	}
}

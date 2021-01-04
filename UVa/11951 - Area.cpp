/*
 * 11951 - Area.cpp
 */
#include <iostream>

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		int height, width, max_money;
		long long int matrix[101][101];
		scanf("%d %d %d", &height, &width, &max_money);

		for (int y = 0; y < height; y++)
			for (int x = 0; x < width; x++) {
				std::cin >> matrix[y][x];
				if (y > 0)
					matrix[y][x] += matrix[y - 1][x];
				if (x > 0)
					matrix[y][x] += matrix[y][x - 1];
				if (y > 0 && x > 0)
					matrix[y][x] -= matrix[y - 1][x - 1];
			}

		int sub_rec, area = 0;
		long long int cost = 0;
		for (int y1 = 0; y1 < height; y1++)
			for (int x1 = 0; x1 < width; x1++)
				for (int y2 = y1; y2 < height; y2++) {
					for (int x2 = x1; x2 < width; x2++) {
						sub_rec = matrix[y2][x2];
						if (y1 > 0)
							sub_rec -= matrix[y1 - 1][x2];
						if (x1 > 0)
							sub_rec -= matrix[y2][x1 - 1];
						if (y1 > 0 && x1 > 0)
							sub_rec += matrix[y1 - 1][x1 - 1];
						if (sub_rec > max_money)
							break;
						if ((y2 - y1 + 1) * (x2 - x1 + 1) > area
								|| ((y2 - y1 + 1) * (x2 - x1 + 1) == area
										&& sub_rec < cost))
							cost = sub_rec, area = (y2 - y1 + 1) * (x2 - x1 + 1);
					}
				}
		printf("Case #%d: %d ", i, area);
		std::cout << cost << std::endl;
	}
}

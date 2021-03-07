/*
 * Find the Spruce.cpp
 */
#include <iostream>
#include <vector>

std::vector<std::vector<char>> m;
std::vector<std::vector<int>> pre_sum;

int r, c;

bool bound(int y, int xl, int xr, int len) {
	if (xl < 0 || y < 0 || xl >= c || y >= r || xr < 0 || xr >= c) {
//		std::cout << "asd";

		return false;
	}

	if (xl == 0) {
		if (pre_sum[y][xr] != 2 * len + 1)
			return false;
//		std::cout << "er";

		return true;
	}
	if (pre_sum[y][xr] - pre_sum[y][xl - 1] != len * 2 + 1) {
//		std::cout << "cnt";

		return false;
	}
	return true;
}

int find_spruce(int y, int x) {
	for (int i = y, len = 0;; i++) {
		if (!bound(i, x - len, x + len, len)) {
//			std::cout << y << " " << x << " " << len << "\n";
			return len;

		}
		len++;
	}
	return 0;
}

void solve() {
	long long int cnt = 0;
	std::cin >> r >> c;
//	std::cout << r << " " << c << "\n";
	m.assign(r, std::vector<char>(c, '.'));

	pre_sum.assign(r, std::vector<int>(c, 0));

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			if (j > 0)
				pre_sum[i][j] = pre_sum[i][j - 1];
			std::cin >> m[i][j];
			if (m[i][j] == '*')
				pre_sum[i][j]++;
		}
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++)
//			std::cout << pre_sum[i][j] << " ";
//		puts("");
//	}
//	puts("");
//	std::cout << find_spruce(0, 1) << "\n";
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (m[i][j] == '*')
				cnt += find_spruce(i, j);

	std::cout << cnt << "\n";
}

int main() {
	int tc = 1;
	std::cin >> tc;

	while (tc--)
		solve();
}

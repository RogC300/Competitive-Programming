/*
 * 11463 - Commandos.cpp
 */
#include <iostream>
#include <vector>

typedef std::vector<int> vi;
typedef std::vector<vi> vii;

int main() {
	int tc;
	std::cin >> tc;
	for (int c = 1; c <= tc; c++) {
		int n, m;
		std::cin >> n >> m;
		vii map(n, vi(n, 1e9));
		for (int i = 0; i < n; i++)
			map[i][i] = 0;

		int a, b;
		while (m--)
			std::cin >> a >> b, map[a][b] = 1, map[b][a] = 1;

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					map[i][j] = std::min(map[i][j], map[i][k] + map[k][j]);

		int s, d;
		std::cin >> s >> d;

		int max = 0;
		for (int k = 0; k < n; k++)
			if (map[s][k] != 1e9 && map[k][d] != 1e9)
				max = std::max(map[s][k] + map[k][d], max);
		printf("Case %d: %d\n", c, max);
	}
}

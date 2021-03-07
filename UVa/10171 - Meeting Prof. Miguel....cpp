/*
 * 10171 - Meeting Prof. Miguel....cpp
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define INF 1e9

typedef std::vector<int> vi;
typedef std::vector<vi> vii;

void floyd_warshall(vii& map) {
	for (int k = 0; k < 26; k++)
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++)
				map[i][j] = std::min(map[i][j], map[i][k] + map[k][j]);

}

void set(vii &a, vii&b) {
	a.assign(26, vi(26, INF)), b.assign(26, vi(26, INF));
	for (int i = 0; i < 26; i++)
		a[i][i] = 0, b[i][i] = 0;
}

int main() {
	int edges;
	vii young, old;

	char age, direction, a, b;
	int v, u, w;

	char start_y, start_o;

	int min_dist;
	std::vector<char> ans;

	while (std::cin >> edges && edges != 0) {
		young.clear(), old.clear(), set(young, old);
		while (edges--) {
			std::cin >> age >> direction >> a >> b >> w;
			if (a == b)
				continue;
			v = a - 'A', u = b - 'A';
			if (age == 'Y') {
				young[v][u] = w;
				if (direction == 'B')
					young[u][v] = w;
			} else {
				old[v][u] = w;
				if (direction == 'B')
					old[u][v] = w;
			}
		}
		std::cin >> start_y >> start_o;
		floyd_warshall(young), floyd_warshall(old);

		min_dist = INF, ans.clear();
		for (int i = 0; i < 26; i++)
			if (young[start_y - 'A'][i] + old[start_o - 'A'][i] < min_dist)
				min_dist = young[start_y - 'A'][i] + old[start_o - 'A'][i];

		if (min_dist != INF) {
			printf("%d ", min_dist);
			for (int i = 0; i < 26; i++)
				if (young[start_y - 'A'][i] + old[start_o - 'A'][i] == min_dist)
					ans.push_back('A' + i);
			std::sort(ans.begin(), ans.end());
			for (int i = 0; i < (int) ans.size(); i++)
				std::cout << ans[i] << (i == (int) ans.size() - 1 ? "\n" : " ");
		} else
			puts("You will never meet.");
	}
}

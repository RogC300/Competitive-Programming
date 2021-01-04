/*
 * 10285 - Longest Run on a Snowboard.cpp
 */
#include <iostream>
#include <vector>

typedef std::vector<int> vi;
typedef std::vector<vi> vii;

int c_y[4] = { 0, 0, -1, 1 };
int c_x[4] = { 1, -1, 0, 0 };

int rows, columns;
vii map, length_map;
std::string name;

bool valid(int y, int x) {
	return (y < rows && y >= 0 && x < columns && x >= 0);
}

int longest_path(int y, int x, int length) {
	int max = 0;
	bool adj = false;
	if (length_map[y][x] != 0)
		return length + length_map[y][x];

	for (int i = 0, tY, tX; i < 4; i++) {
		tY = y + c_y[i], tX = x + c_x[i];
		if (valid(tY, tX) && map[tY][tX] < map[y][x]) {
			max = std::max(longest_path(tY, tX, length + 1), max);
			adj = true;
		}
	}
	if (!adj)
		return length + 1;

	return max;
}

void input() {
	std::cin >> name >> rows >> columns;
	map.clear(), map.resize(rows), length_map.clear();
	length_map.assign(rows, vi(columns, 0));
	for (int i = 0; i < rows; i++)
		for (int j = 0, temp; j < columns; j++)
			std::cin >> temp, map[i].push_back(temp);
}

void p_multi_v(std::vector<std::vector<int>> v) {
	puts("");
	for (int i = 0; i < (int) v.size(); i++)
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << v[i][j] << (j == (int) v[i].size() - 1 ? "\n" : " ");
	puts("");
}

int main() {
	int tc;
	std::cin >> tc;
	while (tc--) {
		input();
		int max = 0;
//		p_multi_v(length_map);

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++) {
				int path = longest_path(i, j, 0);
				max = std::max(path, max);
				length_map[i][j] = path;
			}
		std::cout << name << ": " << max << "\n";
//		p_multi_v(length_map);
	}
}

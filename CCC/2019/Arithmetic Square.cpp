/*
 * Arithmetic Square.cpp
 */
#include <iostream>
#include <vector>

int null = -1e9;
std::vector<std::vector<int>> m(3, std::vector<int>(3));

void fill() {
	for (int i = 0; i < 3; i++) {
		if (m[i][0] != null && m[i][1] != null)
			m[i][2] = (m[i][1] + (m[i][1] - m[i][0]));
		if (m[i][0] != null && m[i][2] != null)
			m[i][1] = (m[i][0] + ((m[i][2] - m[i][0]) / 2));
		if (m[i][1] != null && m[i][2] != null)
			m[i][0] = (m[i][1] - (m[i][2] - m[i][1]));
	}
	for (int i = 0; i < 3; i++) {
		if (m[0][i] != null && m[1][i] != null)
			m[2][i] = (m[1][i] + (m[1][i] - m[0][i]));
		if (m[0][i] != null && m[2][i] != null)
			m[1][i] = (m[0][i] + ((m[2][i] - m[0][i]) / 2));
		if (m[1][i] != null && m[2][i] != null)
			m[0][i] = (m[1][i] - (m[2][i] - m[1][i]));
	}
}

int cnt_col(int c) {
	int cnt = 0;
	for (int i = 0; i < 3; i++)
		if (m[i][c] != null)
			cnt++;
	return cnt;
}
int cnt_row(int r) {
	int cnt = 0;
	for (int i = 0; i < 3; i++)
		if (m[r][i] != null)
			cnt++;
	return cnt;
}

void five_filled() {
	int d = null;
	for (int i = 0; i < 3; i++)
		if (cnt_row(i) == 3)
			d = m[i][1] - m[i][0];

	for (int i = 0; i < 3; i++) {
		if (cnt_row(i) == 3)
			continue;
		if (m[i][0] != null)
			m[i][1] = m[i][0] + d, m[i][2] = m[i][0] + 2 * d;
		if (m[i][1] != null)
			m[i][0] = m[i][1] - d, m[i][2] = m[i][0] + 2 * d;
		if (m[i][2] != null)
			m[i][1] = m[i][2] - d, m[i][0] = m[i][2] - 2 * d;
	}
}

bool check(std::vector<std::vector<int>> v) {
	for (int i = 0; i < 3; i++) {
		if (v[i][1] - v[i][0] != v[i][2] - v[i][1])
			return false;
		if (v[1][i] - v[0][i] != v[2][i] - v[1][i])
			return false;
	}
	return true;
}

void no_line() {
	std::vector<std::vector<int>> tmp = m;
	int i, j, c = 0;
	int x_p[4] = { 0, 1, 0, -1 };
	int y_p[4] = { 1, 0, -1, 0 };

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			if (m[i][j] != null) {
				c = m[i][j];
				break;
			}
		if (c != 0)
			break;
	}
	for (int k = 0, x, y; k < 4; k++) {
		x = j + x_p[k], y = i + y_p[k];
		if (x < 0 || x >= 3 || y < 0 || y >= 3)
			break;
		m = tmp;
		m[y][x] = c;
		fill(), fill(), five_filled();
		if (check(m))
			return;
	}
}

void three_filled() {
	bool line = false;
	for (int i = 0; i < 3; i++)
		if (cnt_row(i) == 3 || cnt_col(i) == 3)
			line = true;

	if (!line) {
		no_line();
		return;
	}

	bool fill_r = true, fill_c = true;
	for (int i = 0; i < 3; i++) {
		if (cnt_row(i) == 1 && fill_r) {
			m[i][0] = m[i][1] = m[i][2] = std::max(m[i][0],
					std::max(m[i][1], m[i][2]));
			fill_c = false;
		}
		if (cnt_col(i) == 1 && fill_c) {
			m[0][i] = m[1][i] = m[2][i] = std::max(m[0][i],
					std::max(m[1][i], m[2][i]));
			fill_r = false;
		}
	}

}

void one_fill() {
	int non_null = -1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (m[i][j] != null)
				non_null = m[i][j];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m[i][j] = non_null;
}

int main() {
	std::string in;
	int num_filled = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			std::cin >> in, in == "X" ? m[i][j] = null : m[i][j] = stoi(in);

	fill(), fill();
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			num_filled = num_filled + (m[i][j] == null ? 0 : 1);

	if (num_filled == 0)
		m[0][0] = 1, num_filled++;
	if (num_filled == 1)
		one_fill();
	if (num_filled == 3 || num_filled == 2)
		three_filled();
	if (num_filled == 5)
		five_filled();

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			std::cout << m[i][j] << " ";
		std::cout << "\n";
	}
}

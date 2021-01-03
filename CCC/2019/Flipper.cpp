/*
 * Flipper.cpp
 */
#include <iostream>
#include <algorithm>

int main() {
	std::string cmd;
	int h = 0, v = 0, arr[2][2] = { { 1, 2 }, { 3, 4 } };

	std::cin >> cmd;
	h = std::count(cmd.begin(), cmd.end(), 'H') % 2;
	v = std::count(cmd.begin(), cmd.end(), 'V') % 2;
	if (h) {
		std::swap(arr[0][0], arr[1][0]);
		std::swap(arr[0][1], arr[1][1]);
	}
	if (v) {
		std::swap(arr[0][0], arr[0][1]);
		std::swap(arr[1][0], arr[1][1]);
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			std::cout << arr[i][j] << " ";
		puts("");
	}
}

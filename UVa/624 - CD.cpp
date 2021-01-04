/*
 * 624 - CD.cpp
 */
#include <iostream>
#include <vector>
#include <string.h>

std::vector<int> tracks, path, tmp_path;
int n, tape, max = 0;

void recurse(int sum, int index) {
	if (sum > max)
		max = sum, path = tmp_path;
	for (int i = index; i < n; i++)
		if (sum + tracks[i] <= tape) {
			tmp_path.push_back(tracks[i]);
			recurse(sum + tracks[i], i + 1);
			tmp_path.pop_back();
		}
}

void print_vec(std::vector<int> v) {
	for (int i = 0; i < (int) v.size(); i++)
		std::cout << v[i] << " ";
}

int main() {
	while (std::cin >> tape >> n) {
		max = 0;
		path.clear();
		tracks.clear();
		tmp_path.clear();
		for (int i = 0, t; i < n; i++)
			std::cin >> t, tracks.push_back(t);
		recurse(0, 0);
		print_vec(path);
		printf("sum:%d\n", max);
	}
}

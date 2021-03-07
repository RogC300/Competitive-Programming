/*
 * Musical Scales.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

std::string no[12] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};


int num (std::string note) {

	for (int i = 0; i < 12; i++)
		if (note == no[i])
			return i;

	return 0;
}

int main() {
	std::vector <std::set <int>> scales(12);
	int up[7] = {2, 2, 1, 2, 2, 2, 1};
	for (int i = 0; i < 12; i++) {
		scales[i].insert (i);

		for (int j = 0, temp = i; j < 7; j++) {
			temp += up[j];
			temp %= 12;
			scales[i].insert (temp);
		}
	}

//	for (int i = 0; i < 12; i++) {
//		for (auto j : scales[i])
//			std::cout << j << " ";
//		std::cout << "\n";
//	}

	int n;
	std::set <int> s;

	std::cin >> n;
	std::string in;
	for (int i = 0; i < n; i++)
		std::cin >> in, s.insert (num(in));
	std::vector <std::string> ans;

	for (int i = 0; i < 12; i++) {
		bool can = true;
		for (auto j : s) {
			if (scales[i].count(j) == 0)
				can = false;
		}

		if (can)
			ans.push_back (no[i]);
	}

	if (ans.size() == 0)
		std::cout << "none";
	else
		for (auto i : ans)
			std::cout << i << " ";



}


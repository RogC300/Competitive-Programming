/*
 * Unicycle Counting.cpp
 */
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

typedef std::vector<int> vi;
typedef std::set<int> si;

void ps(std::set<int> s) {
	for (auto i : s)
		std::cout << i << " ";
	puts("");
}

bool set_compare (si a, si b) {
	return a.size() > b.size();
}

void generate_all(std::vector<std::set<int>> &s, vi marks, int road) {
	std::set<int> in, used;
	bool path[105] = { false }, seen;
	for (int i = 0; i < (int) marks.size(); i++)
		path[marks[i]] = true;

	for (int k = 0, j, d; k < (int) marks.size(); k++) {
		for (int i = k + 1; i < (int) marks.size(); i++) {
			d = marks[i] - marks[k], in.clear(), in.insert(marks[k]), seen =
					false;
			if (marks[k] - d >= 0)
				continue;
			for (j = marks[i]; j < 100 && path[j] == 1; j += d)
				in.insert(j);
			if (j < road)
				continue;
			for (auto l : s)
				if (std::includes(l.begin(), l.end(), in.begin(), in.end())) {
					seen = true;
					break;
				}
			if (!seen)
				s.push_back(in), used.insert (in.begin(), in.end());
		}
	}
	for (int i = 0; i < (int)marks.size(); i++)
		if (used.count (marks[i]) == 0)
			s.push_back ({marks[i]});
}

int min_cycles, num_marks;

void recurse(si used, int i, std::vector<si> combos, int cycles) {
	if ((int) used.size() == num_marks)
		min_cycles = std::min(cycles, min_cycles);
	if (i == (int) combos.size() || cycles >= min_cycles)
		return;

//	ps (used);

	recurse(used, i + 1, combos, cycles);

	if (std::includes(used.begin(), used.end(), combos[i].begin(),
			combos[i].end()))
		return;

	used.insert(combos[i].begin(), combos[i].end());
	recurse(used, i + 1, combos, cycles + 1);

}

int main() {
	int road_length;
	vi marks;
	std::vector<std::set<int>> possible;

	while (std::cin >> road_length >> num_marks) {
		min_cycles = 1e9, possible.clear(), marks.clear();
		for (int i = 0, m; i < num_marks; i++)
			std::cin >> m, marks.push_back(m);
		std::sort(marks.begin(), marks.end());

		generate_all(possible, marks, road_length);
		std::sort (possible.begin(), possible.end(), set_compare);

//		for (int i = 0; i < (int) possible.size(); i++)
//			ps(possible[i]);

		recurse(si(), 0, possible, 0);
		std::cout << min_cycles << "\n";
	}
}

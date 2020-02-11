/*
 * Watering Grass.cpp
 */
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

typedef std::pair<double, double> pdd;

int main() {
	int nodes, length, width, n_sprink, in_pos, r;
	double h_width, off_set, pos1, pos2, pos;
	std::vector<pdd> segment;

	while (std::cin >> nodes >> length >> width) {
		h_width = width / 2.0, segment.clear(), pos = 0.0, n_sprink = 0;

		for (int i = 0; i < nodes; i++) {
			std::cin >> in_pos >> r;
			if (r > h_width) {
				off_set = sqrt(r * r - h_width * h_width);
				pos1 = std::max(0.0, in_pos - off_set);
				pos2 = std::min((double) length, in_pos + off_set);
				segment.push_back( { pos1, pos2 });
			}
		}
		std::sort(segment.begin(), segment.end());
//		for (auto i : segment)
//			std::cout << i.first << " " << i.second << "\n";

		pdd best(0, 0);
		for (auto seg : segment) {
			if (seg.first > pos) {
				if (best == pdd(0, 0) || best.second < seg.first) {
					n_sprink = -1;
					break;
				}
				pos = best.second;
				best.first = best.second = 0;
				n_sprink++;
			}
			if (best == pdd(0, 0) || best.second < seg.second)
				best = seg;
		}
		if (n_sprink == -1
				|| (pos < length && (best == pdd(0, 0) || best.second < length)))
			n_sprink = -1;
		else if (pos < length)
			n_sprink++;
		std::cout << n_sprink << "\n";
	}
}

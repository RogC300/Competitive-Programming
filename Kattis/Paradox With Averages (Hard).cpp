/*
 * Paradox With Averages (Hard).cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int tc;
	std::cin >> tc;

	int num_cs, num_ec, move;
	double avg_cs, avg_ec, iq;
	std::vector<double> cs;
	while (tc--) {
		cs.clear(), move = avg_cs = avg_ec = 0;
		std::cin >> num_cs >> num_ec;

		for (int i = 0; i < num_cs; i++)
			std::cin >> iq, avg_cs += iq, cs.push_back(iq);
		for (int i = 0; i < num_ec; i++)
			std::cin >> iq, avg_ec += iq;
		avg_cs /= num_cs, avg_ec /= num_ec;

		std::sort(cs.begin(), cs.end());

		for (auto i : cs)
			if (i < avg_cs && i > avg_ec)
				move++;
		std::cout << move << "\n";
	}
}

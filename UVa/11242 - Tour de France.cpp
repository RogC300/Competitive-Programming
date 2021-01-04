/*
 * 11242 - Tour de France.cpp
 */
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

int main() {
	int num_f, num_r;
	while (std::cin >> num_f) {
		if (num_f == 0)
			break;
		std::vector<double> f, r, ratio;
		double spread = 0;
		std::cin >> num_r;
		for (int i = 0, n; i < num_f; i++)
			std::cin >> n, f.push_back((double) n);
		for (int i = 0, n; i < num_r; i++)
			std::cin >> n, r.push_back((double) n);

		for (int i = 0; i < num_f; i++)
			for (int j = 0; j < num_r; j++)
				ratio.push_back(r[j] / f[i]);
		std::sort(ratio.begin(), ratio.end());

		for (int i = 1; i < (int) ratio.size(); i++)
			spread = std::max(ratio[i] / ratio[i - 1], spread);
		std::cout << std::fixed << std::setprecision(2) << spread << std::endl;
	}
}

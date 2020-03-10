/*
 * Animal Observation.cpp
 */
#include <iostream>
#include <algorithm>
#include <vector>

typedef std::vector<int> vi;
typedef std::vector<vi> vii;

void print(vii v) {
	for (int i = 0; i < (int) v.size(); i++) {
		for (int j = 0; j < (int) v[i].size(); j++)
			std::cout << v[i][j] << " ";
		std::cout << "\n";
	}
	std::cout << "\n";
}

vii a_sum;

int seg_sum(int beg, int end, int lvl) {
	return a_sum[lvl][end] - (beg < 0 ? 0 : a_sum[lvl][beg]);
}

int main() {
	int days, areas, range;
	vii animals, dp, l_max, r_max;

	std::cin >> days >> areas >> range;
	animals.assign(days + 1, vi(areas, 0));
	a_sum.resize(days + 1, vi(areas, 0));
	dp.assign(days, vi(areas, 0));
	l_max.resize(days, vi(areas));
	r_max.resize(days, vi(areas));

	for (int i = 0; i < days; i++)
		for (int j = 0; j < areas; j++) {
			std::cin >> animals[i][j];
			a_sum[i][j] = j > 0 ? a_sum[i][j - 1] : 0;
			a_sum[i][j] += animals[i][j];
		}

//	print(animals);
//	print(a_sum);
//	print(dp);
//	print(l_max);
//	print(r_max);

	areas--;
	for (int i = 0; i < days; i++) {
		for (int j = 0, see, max; j <= areas - range + 1; j++) {
//			std::cout << "\n\n";
			see = seg_sum(j - 1, j + range - 1, i)
					+ seg_sum(j - 1, j + range - 1, i + 1), max = 0;
			if (i == 0) {
				dp[i][j] = see;
				continue;
			}
//			std::cout << see << " :  ";

			for (int k = std::max(0, j - range + 1);
					k <= std::min(areas - range + 1, j + range - 1); k++) {
				max = std::max(max,
						dp[i - 1][k] + see
								- seg_sum(std::max(j - 1, k - 1),
										std::min(j + range - 1, k + range - 1),
										i));
//				std::cout << dp[i - 1][k] << " " << see << " " << seg_sum(std::max(j - 1, k - 1),
//						std::min(j + range - 1, k + range - 1),
//						i) << "\n";
			}
//			puts ("");
//			std::cout << j - range + 1 << " "
//					<< std::min(areas - range + 1, j + range - 1) << "\n";

			if (j >= range)
				max = std::max(max, l_max[i - 1][j - range] + see);
			if (j + range - 1 <= areas - range)
				max = std::max(max, r_max[i - 1][j + range] + see);
//			std::cout << max << "  : \n";
//			std::cout << r_max[i - 1][j + range] + see << "\n";
			dp[i][j] = max;
		}
		for (int j = 0; j <= areas - range + 1; j++)
			l_max[i][j] = std::max((j == 0 ? 0 : l_max[i][j - 1]), dp[i][j]);
		for (int j = areas - range + 1; j >= 0; j--)
			r_max[i][j] = std::max(
					(j == areas - range + 1 ? 0 : r_max[i][j + 1]), dp[i][j]);
	}
//	print(dp);
//	print(l_max);
//	print(r_max);

	std::cout << *std::max_element(dp[days - 1].begin(), dp[days - 1].end());
}

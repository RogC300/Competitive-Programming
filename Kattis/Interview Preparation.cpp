/*
 * Interview Preparation.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int skill_a, skill_b, t, t_a, t_b, c, max_jobs = 0;
	long long int a, b;
	std::vector<double> final, initial;
	std::cin >> skill_a >> skill_b >> t >> t_a >> t_b >> c;

	while (c--) {
		std::cin >> a >> b;
		a -= skill_a, a < 0 ? a = 0 : 1;
		b -= skill_b, b < 0 ? b = 0 : 1;
		if (a * t_a + b * t_b <= t)
			initial.push_back(a), final.push_back((t - b * t_b) / (1.0 * t_a));
	}
	std::sort(final.begin(), final.end());
	std::sort(initial.begin(), initial.end());

	for (int i = 0, final_i = 0, count = 0; i < (int) initial.size(); i++) {
		count++;
		while (initial[i] > final[final_i])
			count--, final_i++;
		max_jobs = std::max(max_jobs, count);
	}
	std::cout << max_jobs;
}

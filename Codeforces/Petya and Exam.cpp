/*
 * Petya and Exam.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int questions, time, max, n;
	long long int e, h, n_e, n_h;
	std::vector<std::pair<int, int>> exam;

	std::cin >> n;

	while (n--) {
		std::cin >> questions >> time >> e >> h;
		exam.resize(questions), n_e = n_h = max = 0;

		for (int i = 0; i < questions; i++)
			std::cin >> exam[i].second, exam[i].second == 0 ? n_e++ : n_h++;
		for (int i = 0; i < questions; i++)
			std::cin >> exam[i].first;
		std::sort(exam.begin(), exam.end());

		long long int e_u = 0, h_u = 0;
		for (int i = 0, sol; i < questions; i++) {
			long long int t;
			if (i > 0)
				exam[i - 1].second == 0 ? e_u++ : h_u++;
			t = exam[i].first - 1;
			if (t >= e_u * e + h_u * h) {
				sol = e_u + h_u;
				t -= e_u * e + h_u * h;
				if (t / e >= n_e - e_u) {
					sol += n_e - e_u, t -= e * (n_e - e_u);
					if (t / h >= n_h - h_u)
						sol += n_h - h_u;
				} else
					sol += t / e;
				max = std::max(max, sol);
			}
		}
		if (e * n_e <= time - h * n_h)
			max = n_e + n_h;
		std::cout << max << "\n";
	}
}

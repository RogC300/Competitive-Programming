/*
 * Stack of Presents.cpp
 */
#include <iostream>
#include <map>

int main() {
	int n_pres, list, tc;
	long long int time;
	std::map<int, int> pres;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n_pres >> list;
		time = 0, pres.clear();
		for (int i = 0, p; i < n_pres; i++)
			std::cin >> p, pres[p] = i;

		for (int i = 0, p, cnt = 0, left = -1; i < list; i++) {
			std::cin >> p;
			if (left > pres[p])
				time++, cnt++;
			else
				time += 2 * (pres[p] - cnt) + 1, cnt++;
			left = std::max(left, pres[p]);
		}
		std::cout << time << "\n";
	}
}

/*
 * Just Eat It!.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int n_cup, tc;
	long long int max_taste, total_taste, temp_t;
	std::vector<int> taste;
	bool start;

	std::cin >> tc;
	while (tc--) {
		std::cin >> n_cup, taste.resize(n_cup);
		max_taste = total_taste = temp_t = 0;
		start = true;
		for (int i = 0; i < n_cup; i++)
			std::cin >> taste[i], total_taste += taste[i];

		for (int i = 0; i < n_cup; i++) {
			temp_t += taste[i];
			temp_t <= 0 ? temp_t = 0, start = false : 1;
			if (temp_t > max_taste) {
				max_taste = temp_t;
				if (i == n_cup - 1 && temp_t == total_taste && start)
					max_taste = -1;
			}
		}
		std::cout << (total_taste > max_taste ? "YES\n" : "NO\n");
	}
}

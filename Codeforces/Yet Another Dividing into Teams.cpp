/*
 * Yet Another Dividing into Teams.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

/*
 int main() {
 int n, used, teams, last_used, tc;
 std::vector<int> skill;

 std::cin >> tc;

 while (tc--) {
 std::cin >> n;
 skill.resize(n), used = teams = 0;

 for (int i = 0; i < n; i++)
 std::cin >> skill[i];
 std::sort(skill.begin(), skill.end());

 while (used != n) {
 last_used = -1;
 for (int i = 0; i < n; i++)
 if (skill[i] != -1
 && (last_used != skill[i] - 1 || last_used == -1))
 used++, last_used = skill[i], skill[i] = -1;
 teams++;
 }
 std::cout << teams << "\n";
 }
 }
 */
// answer can only be 1 or 2, think about it
int main() {
	std::vector<int> k;
	int n, tc;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n, k.resize(n);

		bool y = false;

		for (int i = 0; i < n; i++)
			std::cin >> k[i];
		std::sort(k.begin(), k.end());
		for (int i = 1; i < n; i++)
			if (k[i] == k[i - 1] + 1) {
				y = true;
				break;
			}
		std::cout << (y ? "2" : "1") << "\n";
	}
}

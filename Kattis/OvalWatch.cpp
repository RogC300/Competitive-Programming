/*
 * OvalWatch.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int number_of_players, number_of_legs;
	std::cin >> number_of_players >> number_of_legs;
	std::vector<std::vector<int>> ghost_leg(number_of_legs);
	std::vector<int> players(number_of_players);

	for (int i = 0; i < number_of_players; i++)
		players[i] = i;
	for (int i = 0; i < number_of_legs; i++)
		ghost_leg[i].resize(2), std::cin >> ghost_leg[i][0] >> ghost_leg[i][1];
	std::sort(ghost_leg.begin(), ghost_leg.end(),
			[](std::vector<int> &a, std::vector <int>& b) {return a[1] < b[1];});
	for (int i = 0; i < number_of_legs; i++)
		std::swap(players[ghost_leg[i][0]], players[ghost_leg[i][0] + 1]);

//	for (int i = 0; i < number_of_legs; i++)
//		printf ("%d %d\n", ghost_leg[i][0], ghost_leg[i][1]);
//	for (int i = 0; i < number_of_players; i++)
//		std::cout << players[i] << " ";

	for (int i = 0; i < number_of_players; i++)
		for (int j = 0; j < number_of_players; j++)
			if (players[j] == i) {
				std::cout << j << " ";
				break;
			}
}

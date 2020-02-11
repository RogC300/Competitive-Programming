/*
 * Exploding Kittens.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int playerAmount, explKittAmount, defuseAmount;
	scanf("%d %d %d", &playerAmount, &explKittAmount, &defuseAmount);
	std::vector<int> players, playerHand, explKitt(explKittAmount), defuse(
			defuseAmount);

	for (int i = 0; i < playerAmount; i++)
		playerHand.push_back(0), players.push_back(i);
	for (int i = 0; i < explKittAmount; i++)
		scanf("%d", &explKitt[i]);
	for (int i = 0; i < defuseAmount; i++)
		scanf("%d", &defuse[i]);

	int inEx = 0, inDe = 0, player = 0, previousCom;
	while (inEx < explKittAmount || inDe < defuseAmount) {
		if (players.size() == 1) break;
		if (inDe == defuseAmount || (inEx < explKittAmount && explKitt[inEx] < defuse[inDe])) {
			player = (player+explKitt[inEx]) % playerAmount;

			playerHand[players[player]]--;
			std::cout << players[player] << ": " << playerHand[players[player]] <<  "\n";
			if (playerHand[players[player]] < 0)
				players.erase(players.begin()+player), playerAmount--;
			inEx++;
		}
		if (players.size() == 1) break;
		if (inEx == explKittAmount || (inDe < defuseAmount && defuse[inDe] < explKitt[inEx])) {
			player = (player+defuse[inDe]) % playerAmount;
			playerHand[players[player]]++;
			std::cout << players[player] << ": " << playerHand[players[player]] <<  "\n";
			inDe++;
		}
	}
	if (players.size() == 1)
		std::cout << players[0];
	else
		std::cout << -1;
}

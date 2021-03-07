/*
 * 462 - Bridge Hand Evaluator.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>

char suits[4] = { 'C', 'D', 'H', 'S' };
char special[4] = { 'J', 'Q', 'K', 'A' };

void output(std::vector<std::vector<char>> cards) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < (int) cards[i].size(); j++)
			std::cout << cards[i][j] << " ";
		std::cout << "\n";
	}
}

int main() {
	std::string s;
//	std::getline (std::cin, s);
	while (getline(std::cin, s)) {
		std::vector<std::vector<char>> cards(4);
		int points = 0, ignorePoints;
		std::vector<bool> stopped(4);
		bool allStop = true;
		std::fill(stopped.begin(), stopped.end(), false);
		for (int i = 0; i < 39; i += 3) {
			char rank = s[i], suit = s[i + 1];
			for (int i = 0; i < 4; i++)
				if (suit == suits[i])
					cards[i].push_back(rank);
			for (int i = 0; i < 4; i++)
				if (rank == special[i])
					points += (i + 1);
		}
		char highestCards;
		int highestSuit = 0;
		for (int i = 0; i < 4; i++) {
			int size = cards[i].size();
			if (size >= highestSuit) {
				highestCards = suits[i];
				highestSuit = size;
			}

			for (int j = 0; j < size; j++) {
				if (cards[i][j] == 'K' && size == 1)
					points--;
				if (cards[i][j] == 'Q' && (size == 1 || size == 2))
					points--;
				if (cards[i][j] == 'J' && (size == 1 || size == 2 || size == 3))
					points--;
				if (cards[i][j] == 'A' || (cards[i][j] == 'K' && size >= 2)
						|| (cards[i][j] == 'Q' && size >= 3))
					stopped[i] = true;
			}
		}
		ignorePoints = points;
		for (int i = 0; i < 4; i++)
			if (stopped[i] == false)
				allStop = false;

		for (int i = 0; i < 4; i++) {
			int size = cards[i].size();
			if (size == 2)
				points++;
			if (size == 1 || size == 0)
				points += 2;
		}

		if (points < 14)
			std::cout << "PASS\n";
		else if (ignorePoints >= 16 && allStop == true)
			std::cout << "BID NO-TRUMP\n";
		else
			std::cout << "BID " << highestCards << std::endl;
		//	std::cout << points << std::endl;
//		output (cards);
	}
}


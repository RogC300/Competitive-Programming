/*
 * Poker Hand.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <map>
#include <iterator>

int main() {
	std::map<char, int> hand;
	std::map<char, int>::iterator itr;
	int max = 0;
	for (int i = 0; i < 5; i++) {
		std::string card;
		std::cin >> card;
		if (hand.find(card[0]) == hand.end())
			hand.insert(std::pair<char, int>(card[0], 1));
		else
			hand[card[0]]++;
	}
	for (itr = hand.begin(); itr != hand.end(); itr++)
		max = std::max(max, itr->second);
	std::cout << max;
}

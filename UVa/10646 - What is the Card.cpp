/*
 * 10646 - What is the Card.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <stack>
#include <deque>

char conversion[8] = { '2', '3', '4', '5', '6', '7', '8', '9' };

int convert(std::string rank) {
	for (int i = 0; i < 8; i++)
		if (rank[0] == conversion[i])
			return i + 2;
	return 10;
}

void showstack(std::stack<std::string> s) {
	while (!s.empty()) {
		std::cout << '\n' << s.top();
		s.pop();
	}
	std::cout << '\n';
}

int main() {
	int runs, number = 1;
	std::cin >> runs;
	for (int i = 0; i < runs; i++) {
		int y = 0;
		std::stack<std::string> pile;
		std::deque<std::string> hand;
		for (int i = 0; i < 52; i++) {
			std::string temp;
			std::cin >> temp;
			pile.push(temp);
		}
		for (int i = 0; i < 25; i++)
			hand.push_back(pile.top()), pile.pop();
		for (int i = 0; i < 3; i++) {
			int rank = convert(hand.front());
			y += rank;
			hand.pop_front();
			for (int i = 0; i < (10 - rank); i++)
				pile.pop();
		}
		while (!hand.empty()) {
			pile.push(hand.back());
			hand.pop_back();
		}
		y = pile.size() - y - 3;
		//showstack (pile);
		for (int i = 0; i < y; i++)
			pile.pop();
		std::cout << "Case " << number << ": " << pile.top() << std::endl;
		number++;
	}
}

/*
 * Game of Throwns.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <string>
#include <stack>

const std::string undo = "undo";

int main() {
	int numOfChildren, commands, numberUndos, movement;
	std::string input;
	std::stack<int> eggPositions;

	std::cin >> numOfChildren >> commands;
	eggPositions.push(0);

	for (int i = 0; i < commands; i++) {
		std::cin >> input;
		if (input == undo) {
			std::cin >> numberUndos;
			for (int j = 0; j < numberUndos; j++)
				eggPositions.pop();
		} else {
			movement = stoi(input);
			eggPositions.push((((eggPositions.top() + movement) % numOfChildren) + numOfChildren) % numOfChildren);
		}
	}

	std::cout << eggPositions.top() << std::endl;
}

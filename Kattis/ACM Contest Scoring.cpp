/*
 * ACM Contest Scoring.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <map>
#include <iterator>

int main() {
	std::map<char, int> questions;
	std::map<char, int>::iterator itr;
	int sum = 0, solved = 0, Time;
	while (std::cin >> Time) {
		if (Time == -1)
			break;
		char question;
		std::string right;
		std::cin >> question >> right;

		if (questions.find(question) == questions.end()) {
			if (right == "wrong")
				questions.insert(std::pair<char, int>(question, -2));
			else {
				questions.insert(std::pair<char, int>(question, -1));
				sum += Time;
			}
		} else {
			if (right == "wrong")
				questions[question] -= 1;
			else {
				sum += ((questions[question] + 1) * -20) + Time;
				questions[question] = -1;
			}
		}
	}
	for (itr = questions.begin(); itr != questions.end(); ++itr)
		if (itr->second == -1)
			solved++;

	std::cout << solved << " " << sum;
}

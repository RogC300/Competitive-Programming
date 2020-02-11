/*
 * ToLower.cpp
 */
#include <iostream>

int main() {
	int problems, test_cases, number_solved = 0;
	std::cin >> problems >> test_cases;
	std::string word;

	while (problems--) {
		bool solved = true;
		for (int i = 0; i < test_cases; i++) {
			std::cin >> word;
			word[0] = tolower(word[0]);
			for (int i = 0; i < (int) word.length(); i++)
				if (word[i] != tolower(word[i])) {
					solved = false;
					break;
				}
		}
		if (solved)
			number_solved++;
	}
	std::cout << number_solved;
}

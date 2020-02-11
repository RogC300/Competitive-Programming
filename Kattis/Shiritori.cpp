/*
 * Shiritori.cpp
 */
#include <iostream>
#include <vector>
#include <map>

int main() {
	int number_words;
	std::map<std::string, bool> used;
	bool player = true, fair = true;
	std::string w;
	std::vector<std::string> words;
	std::cin >> number_words;
	for (int i = 0; i < number_words; i++)
		std::cin >> w, words.push_back(w), used[w] = false;

	for (int i = 0; i < number_words; i++) {
		if (used[words[i]] == true) {
			fair = false;
			break;
		}
		if (i > 0 && words[i - 1][words[i - 1].length() - 1] != words[i][0]) {
			fair = false;
			break;
		}
		used[words[i]] = true;
		player = !player;
	}
	if (fair)
		std::cout << "Fair Game";
	else
		std::cout << "Player " << (player ? "1" : "2") << " lost";
}

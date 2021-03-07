/*
 * Universal Solution.cpp
 */
#include <iostream>
#include <map>

int main() {
	int tc, max;
	std::string str;
	char end;
	std::map<char, int> game;
	std::map<char, char> win = { { 'R', 'P' }, { 'P', 'S' }, { 'S', 'R' } };

	std::cin >> tc;

	while (tc--) {
		std::cin >> str, game.clear(), max = 0;
		for (int i = 0; i < (int) str.length(); i++)
			game[str[i]]++;

		for (auto i : game)
			max = std::max(i.second, max);
		for (auto i : game)
			if (i.second == max)
				end = win[i.first];
		for (int i = 0; i < (int) str.length(); i++)
			std::cout << end;
		std::cout << "\n";
	}
}

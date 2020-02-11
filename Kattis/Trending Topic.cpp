/*
 * Trending Topic.cpp
 */
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

typedef std::string str;
typedef std::vector<str> vstr;

void last_seven(std::vector<vstr> days, int top) {
	std::map<str, int> words;
	std::map<int, std::set<str>, std::greater<int>> frequency;
	for (int i = days.size() - 1; i >= std::max(0, (int) days.size() - 7);
			i--) {
		for (int j = 0; j < (int) days[i].size(); j++)
			words[days[i][j]]++;
	}
	for (auto i : words)
		frequency[i.second].insert(i.first);

	int count = 0;
	std::cout << "<top " << top << ">\n";

	for (auto i = frequency.begin(); count < top && i != frequency.end(); i++)
		for (auto j : i->second)
			std::cout << j << " " << i->first << "\n", count++;
	std::cout << "</top>\n";
}

int main() {
	std::vector<vstr> days;
	str word;
	int top, index = -1;
	while (!std::cin.eof()) {
		word = "", std::cin >> word;
		if (word == "<text>") {
			index++, days.push_back( { });
			while (std::cin >> word && word != "</text>")
				if (word.length() >= 4)
					days[index].push_back(word);
		}
		if (word == "<top")
			std::cin >> top >> word, last_seven(days, top);
	}
}

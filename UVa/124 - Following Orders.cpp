/*
 * 124 - Following Orders.cpp
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <algorithm>

std::vector<char> available;
bool map[26][26], seen[26];
char path[26];
int n;

void dfs(int index) {
	if (index == n) {
		path[index] = '\0';
		puts(path);
		return;
	}
	for (int i = 0; i < n; i++)
		if (!seen[available[i] - 'a']) {
			for (int j = 0; j < n; j++)
				if (seen[available[j] - 'a'] == true
						&& map[available[i] - 'a'][available[j] - 'a'] == true)
					return;
			path[index] = available[i];
			seen[available[i] - 'a'] = true;
			dfs(index + 1);
			seen[available[i] - 'a'] = false;
		}
}

int main() {
	std::stringstream input;
	std::string line;
	char less, greater;
	bool first = false;
	while (getline(std::cin, line)) {
		std::cout << (first == true ? "\n" : ""), first = true;
		available.clear(), memset(map, false, sizeof map), memset(seen, false,
				sizeof seen), input.clear(), input << line;
		while (input >> less)
			available.push_back(less);
		std::sort(available.begin(), available.end());
		getline(std::cin, line), input.clear(), input << line;
		while (input >> less >> greater)
			map[less - 'a'][greater - 'a'] = true;
		n = available.size();
		dfs(0);
	}
}

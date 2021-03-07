/*
 * 429 - Word Transformation.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <sstream>

std::vector<std::string> dictionary;

int bfs(std::string a, std::string b) {
	std::queue<std::string> q;
	std::map<std::string, int> map;
	q.push(a), map[a] = 0;

	while (!q.empty() && !map.count(b)) {
		std::string word = q.front();
		q.pop();
		for (int i = 0; i < (int) dictionary.size(); i++) {
			std::string d = dictionary[i];
			if (!map.count(d) && d != word && d.length() == word.length()) {
				int diff = 0;
				for (int j = 0; j < (int) word.length(); j++)
					if (word[j] != d[j])
						diff++;
				if (diff == 1)
					q.push(dictionary[i]), map[dictionary[i]] = map[word] + 1;
			}
		}
	}
	return map[b];
}

int main() {
	int tc;
	bool first = false;
	std::cin >> tc;
	while (tc--) {
		std::string v, u, line;
		std::cout << (first == true ? "\n" : ""), first = true;
		while (std::cin >> v && v != "*")
			dictionary.push_back(v);
		std::cin.ignore();
		while (getline(std::cin, line) && line != "") {
			std::stringstream ss(line);
			ss >> v >> u;
			std::cout << v << " " << u << " " << bfs(v, u) << '\n';
		}
	}
}

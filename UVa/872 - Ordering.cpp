/*
 * 872 - Ordering.cpp
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <algorithm>

std::vector<char> avail;
std::vector<std::string> answers;
bool seen[26], map[26][26];
char path[26];
int n;

void dfs(int index) {
	if (index == n) {
		path[index] = '\0';
		answers.push_back(path);
		return;
	}
	for (int i = 0; i < n; i++)
		if (!seen[avail[i] - 'A']) {
			for (int j = 0; j < n; j++)
				if (map[avail[i] - 'A'][avail[j] - 'A'] && seen[avail[j] - 'A'])
					return;
			path[index] = avail[i];
			seen[avail[i] - 'A'] = true;
			dfs(index + 1);
			seen[avail[i] - 'A'] = false;
		}
}

void input() {
	std::stringstream sstream;
	std::string in;
	char c1, c2, sign;
	memset(seen, false, sizeof seen), memset(map, false, sizeof map);
	answers.clear(), avail.clear();
	while (getline(std::cin, in) && in.empty())
		;
	sstream.clear(), sstream << in;
	while (sstream >> c1)
		avail.push_back(c1);
	while (getline(std::cin, in) && in.empty())
		;
	sstream.clear(), sstream << in;
	while (sstream >> c1 >> sign >> c2)
		map[c1 - 'A'][c2 - 'A'] = true;
	n = avail.size();
	std::sort(avail.begin(), avail.end());
}

int main() {
	int tc;
	std::cin >> tc;
	bool first = false;
	while (tc--) {
		std::cout << (first == true ? "\n" : ""), first = true;
		input();
		dfs(0);
		if (answers.size() == 0)
			puts("NO");
		else
			for (int i = 0; i < (int) answers.size(); i++)
				for (int j = 0; j < (int) answers[i].length(); j++)
					std::cout << answers[i][j]
							<< (j == (int) answers[i].length() - 1 ? "\n" : " ");
	}
}

/*
 1

 A B C
 A<B B<C C<A
 */

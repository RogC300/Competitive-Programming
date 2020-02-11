/*
 * Kitten on a Tree.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

std::vector<int> graph[100];

int toInt(std::string x) {
	std::istringstream ss(x);
	int a;
	ss >> a;
	return a;
}

std::vector<int> ssplit(std::string s) {
	std::vector<int> vs;
	std::string subs = "";
	for (int i = 0; i < (int) s.length(); i++) {
		if (i == (int) s.length() - 1) {
			subs += s.substr(i, 1);
			vs.push_back(toInt(subs));
			subs = "";
		} else if (s.substr(i, 1) == " ") {
			vs.push_back(toInt(subs));
			subs = "";
		} else if (s.substr(i, 1) != " ")
			subs += s.substr(i, 1);
	}
	return vs;
}

bool contains(std::vector<int> v, int i) {
	std::vector<int>::iterator it;
	it = find(v.begin(), v.end(), i);
	return it != v.end();
}

int findp(int x) {
	for (int i = 0; i < 100; i++)
		if (contains(graph[i], x))
			return i;
	return -1;
}

int main() {
	int start;
	std::vector<int> path;
	scanf("%d", &start);

	while (true) {
		std::string s = "";
		getline(std::cin, s);
		if (s == "-1")
			break;
		std::vector<int> tm = ssplit(s);

		for (int x = 1; x < (int) tm.size(); x++)
			graph[tm[0] - 1].push_back(tm[x]);
	}
	start--;
	while (true) {
		path.push_back(start + 1);
		if (findp(start + 1) == -1)
			break;
		start = findp(start + 1);
	}
	for (int i = 0; i < (int) path.size(); i++)
		std::cout << path[i] << " ";
}

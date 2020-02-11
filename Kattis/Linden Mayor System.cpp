/*
 * Linden Mayor System.cpp
 */
#include <iostream>
#include <map>

int main() {
	int n, m;
	std::cin >> n >> m;
	std::map<char, std::string> swap;
	std::string start, final = "";
	for (int i = 0; i < n; i++) {
		char a;
		std::string bad, b;
		std::cin >> a >> bad >> b;
		swap[a] = b;
	}
	std::cin >> start;
	for (int i = 0; i < m; i++) {
		for (int i = 0; i < (int) start.length(); i++)
			if (swap.find(start[i]) == swap.end())
				final += start[i];
			else
				final += swap[start[i]];
		start = final;
		final = "";
	}
	std::cout << start;
}

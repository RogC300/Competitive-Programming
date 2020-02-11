/*
 * Pebble Solitaire.cpp
 */
#include <iostream>
#include <map>

int min_pebbles;
std::map<std::string, bool> visit;

void recurse(std::string line, int num_pebbles) {
	if (visit[line])
		return;
	visit[line] = true;
	std::string temp;
	min_pebbles = std::min(num_pebbles, min_pebbles);
	for (int i = 0; i < (int) line.length(); i++) {
		if (i < (int) line.length() - 2 && line[i] == 'o' && line[i + 1] == 'o'
				&& line[i + 2] == '-') {
			temp = line, temp[i + 2] = 'o', temp[i] = '-', temp[i + 1] = '-';
			recurse(temp, num_pebbles - 1);
		}
		if (i > 1 && line[i] == 'o' && line[i - 1] == 'o'
				&& line[i - 2] == '-') {
			temp = line, temp[i - 2] = 'o', temp[i - 1] = '-', temp[i] = '-';
			recurse(temp, num_pebbles - 1);
		}
	}
}

int main() {
	int tc, num_pebbles;
	std::string line;

	std::cin >> tc;
	while (tc--) {
		num_pebbles = 0, min_pebbles = 1e9;

		std::cin >> line;
		for (int i = 0; i < (int) line.length(); i++)
			if (line[i] == 'o')
				num_pebbles++;

		recurse(line, num_pebbles);

		std::cout << min_pebbles << "\n";
	}
}

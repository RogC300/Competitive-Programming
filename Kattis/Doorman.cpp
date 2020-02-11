/*
 * Doorman.cpp
 */
#include <iostream>
#include <map>

int main() {
	int dif, w = 0, m = 0, i;
	std::string in;
	std::map<int, int> count;

	std::cin >> dif >> in;

	for (i = 0; i < (int) in.size(); i++) {
		in[i] == 'W' ? w++ : m++;
		count[i]++;
		if (count[i] > 10)
			break;
		if (abs(w - m) > dif) {
			if (i == (int) in.size() - 1)
				break;
			in[i] == 'W' ? w-- : m--;
			std::swap(in[i], in[i + 1]), i--;
		}
	}
	std::cout << i;
}

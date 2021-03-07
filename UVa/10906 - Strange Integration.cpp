/*
 * 10906 - Strange Integration.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int num_lines;
	std::vector <std::string> equations;

	std::string line, e;

	std::cin >> num_lines;
	std::cin.ignore();

	while (num_lines--) {
		getline (std::cin, line);
		e = line.substr (4);
//		std::cout << e << "\n";
		for (int i = 0; i < (int)e.length(); i++)
			if (e[i] >= 'A')
				e.replace (i, 1, equations[(int)e[i] - 'A']);

		equations.push_back(e);
//		std::cout << e << "\n";
	}

	std::cout << equations [equations.size()-1] << "\n";


}

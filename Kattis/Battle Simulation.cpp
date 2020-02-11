/*
 * Battle Simulation.cpp
 */
#include <iostream>

int main() {
	std::string attacks, sub = "";
	std::cin >> attacks;
	int size = attacks.length();
	for (int i = 0; i < size; i++) {
		sub = "";
		if (i + 2 < size) {
			sub += attacks[i];
			sub += attacks[i + 1];
			sub += attacks[i + 2];
		}
		if (sub == "RBL" || sub == "RLB" || sub == "BRL" || sub == "BLR"
				|| sub == "LRB" || sub == "LBR") {
			std::cout << "C";
			i += 2;
			continue;
		}
		switch (attacks[i]) {
		case 'R':
			printf("S");
			break;
		case 'B':
			printf("K");
			break;
		case 'L':
			printf("H");
			break;
		}
	}
}

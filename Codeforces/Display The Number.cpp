/*
 * Display The Number.cpp
 */
#include <iostream>

int main() {
	int seg, tc;
	std::string num;

	std::cin >> tc;

	while (tc--) {
		std::cin >> seg, num = "";

		for (int i = 0; i < seg / 2; i++)
			num += "1";

		if (seg % 2 == 1)
			num[0] = '7';

		std::cout << num << "\n";
	}
}

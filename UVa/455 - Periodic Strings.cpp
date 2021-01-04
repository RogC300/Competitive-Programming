/*
 * 455 - Periodic Strings.cpp
 */
#include <iostream>

int main() {
	std::string input;
	int len, tc;
	bool flag;

	std::cin >> tc;

	while (tc--) {
		std::cin >> input;
		len = input.length();
		flag = false;

		for (int i = 1; i < len + 1 && !flag; i++) {
			flag = true;
			for (int j = 0; j < len && flag; j++)
				if (input[j] != input[(j + i) % len])
					flag = false;
			if (flag)
				std::cout << i << "\n";
		}
		std::cout << (tc ? "\n" : "");
	}
}

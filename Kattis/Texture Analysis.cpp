/*
 * Texture Analysis.cpp
 */
#include <iostream>

int main() {
	std::string in;
	int last_pxl, len;
	bool even;

	for (int tc = 1;; tc++) {
		std::cin >> in;
		if (in == "END")
			break;
		last_pxl = 0, len = -1, even = true;

		for (int i = 1; i < (int) in.length() && even; i++)
			if (in[i] == '*') {
				if (len == -1)
					len = i - last_pxl, last_pxl = i;
				else if (len != i - last_pxl)
					even = false;
				last_pxl = i;
			}

		std::cout << tc << (even ? " EVEN\n" : " NOT EVEN\n");
	}
}

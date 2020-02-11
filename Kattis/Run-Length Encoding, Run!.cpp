/*
 * Run-Length Encoding, Run!.cpp
 */
#include <iostream>
#include <stdlib.h>

int main() {
	char cmd;
	std::string code;
	std::cin >> cmd >> code;
	if (cmd == 'E') {
		int count = 1;
		for (int i = 0; i < (int) code.length() - 1; i++) {
			if (code[i] != code[i + 1])
				std::cout << code[i] << count, count = 0;
			count++;
		}
		std::cout << code[code.length() - 1] << count;
	} else
		for (int i = 0; i < (int) code.length(); i += 2) {
			char c[1] = { code[i + 1] };
			int count = atoi(c);
			for (int j = 0; j < count; j++)
				std::cout << code[i];
		}
}

/*
 * Palindromifier.cpp
 */
#include <iostream>

int main() {
	std::string s;
	std::cin >> s;

	printf("3\nR %d\nL %d\nL 2", (int) s.length() - 1, (int) s.length());
}

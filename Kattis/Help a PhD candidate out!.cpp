/*
 * Help a PhD candidate out!.cpp
 */
#include <iostream>

int main() {
	int tc;

	std::cin >> tc;

	while (tc--) {
		std::string s;
		std::cin >> s;
		int a, b;

		if (s[0] == 'P') {
			std::cout << "skipped\n";
			continue;
		}
		for (int i = 0; i < (int) s.length(); i++)
			if (s[i] == '+') {
				a = stoi(s.substr(0, i));
				b = stoi(s.substr(i + 1, s.length()));
				break;
			}
		std::cout << a + b << "\n";
	}
}

/*
 * Yet Another Meme Problem.cpp
 */
#include <iostream>
#include <string>

int main() {
	long long a, b;
	int tc;

	std::cin >> tc;

	while (tc--) {
		std::cin >> a >> b;
		std::cout << a * (std::to_string(b + 1).length() - 1) << "\n";
	}
}

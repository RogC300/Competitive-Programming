/*
 * String Coloring (easy version).cpp
 */
#include <iostream>

int main() {
	int length;
	std::string s, ans;
	char cur_a = 'a', cur_b = 'a';
	bool possible = true;

	std::cin >> length >> s;

	for (int i = 0; i < length && possible; i++) {
		if (s[i] >= cur_a)
			ans += '0', cur_a = s[i];
		else if (s[i] >= cur_b)
			ans += '1', cur_b = s[i];
		else
			possible = false;
	}

	if (!possible)
		std::cout << "NO";
	else
		std::cout << "YES\n" << ans;
}

/*
Essentially you can freely shift same digits between each other. Imagine that zeros
are water and ones are blocks that you can shift and move freely, they could all go
to one side or whatever, except they can't go over each other. Here, you realize you
need to increasing subsequences that cover the entire string. So just use a greedy
method to choose and if it doesn't work it's impossible.
 */

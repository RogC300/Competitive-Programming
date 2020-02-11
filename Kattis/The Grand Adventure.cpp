/*
 * The Grand Adventure.cpp
 */
#include <iostream>
#include <stack>

int main() {
	std::string in;
	int n;
	std::cin >> n;
	while (n--) {
		std::stack<char> back;

		std::cin >> in;

		bool y = true;
		for (int i = 0; i < (int) in.size(); i++) {
			if (in[i] == '$' || in[i] == '|' || in[i] == '*')
				back.push(in[i]);

			switch (in[i]) {
			case 't':
				if (back.empty() || back.top() != '|') {
					y = false;
					break;
				} else
					back.pop();
				break;
			case 'j':
				if (back.empty() || back.top() != '*') {
					y = false;
					break;
				} else
					back.pop();
				break;
			case 'b':
				if (back.empty() || back.top() != '$') {
					y = false;
					break;
				} else
					back.pop();
				break;
			}
		}
		if (!back.empty())
			y = false;
		if (y)
			puts("YES");
		else
			puts("NO");
	}
}

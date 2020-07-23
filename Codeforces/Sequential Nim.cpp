/*
 * Sequential Nim.cpp
 */
#include <iostream>

int main() {
	int n, lead_one, tc;
	bool first;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n, first = true, lead_one = 0;
		for (int i = 0, in; i < n; i++) {
			std::cin >> in;
			if (in == 1 && first)
				lead_one++;
			else if (in != 1)
				first = false;
		}
		if (lead_one % 2 == 0)
			std::cout << (n == lead_one ? "Second\n" : "First\n");
		else
			std::cout << (n == lead_one ? "First\n" : "Second\n");
	}
}

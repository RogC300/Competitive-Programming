/*
 * Boboniu Likes to Color Balls.cpp
 */
#include <iostream>

int main() {
	int arr[4], tc;

	std::cin >> tc;

	while (tc--) {
		for (int i = 0; i < 4; i++)
			std::cin >> arr[i];

		if (arr[0] == arr[1] && arr[1] == arr[2]) {
			std::cout << "Yes\n";
			continue;
		}
		int odd = 0;
		for (int i = 0; i < 4; i++)
			if (arr[i] % 2 == 1)
				odd++;

		if (odd == 1 || odd == 4 || odd == 0)
			std::cout << "Yes\n";
		else if (odd == 3 && arr[0] > 0 && arr[1] > 0 && arr[2] > 0)
			std::cout << "Yes\n";
		else
			std::cout << "No\n";
	}
}

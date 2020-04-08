/*
 * Fast Food Restaurant.cpp
 */
#include <iostream>
#include <algorithm>

int main() {
	int food[3], people, tc;

	std::cin >> tc;

	while (tc--) {
		std::cin >> food[0] >> food[1] >> food[2], people = 0;

		for (int i = 0; i < 3; i++)
			if (food[i])
				food[i]--, people++;
		std::sort(std::begin(food), std::end(food), std::greater<>());

		for (int i = 0; i < 3; i++)
			for (int j = i + 1; j < 3; j++)
				if (food[i] && food[j])
					people++, food[i]--, food[j]--;
		if (food[0] && food[1] && food[2])
			people++;

		std::cout << people << "\n";
	}
}

/*
 * Thanos the Hero.cpp
 */
#include <iostream>

int main() {
	int number_of_worlds;
	long long int kill = 0;
	std::cin >> number_of_worlds;
	int worlds[number_of_worlds];

	for (int i = number_of_worlds - 1; i >= 0; i--)
		std::cin >> worlds[i];
	for (int i = 0; i < number_of_worlds - 1; i++)
		if (worlds[i] <= worlds[i + 1])
			kill += worlds[i + 1] - worlds[i] + 1, worlds[i + 1] = worlds[i] - 1;
	for (int i = 0; i < number_of_worlds; i++)
		if (worlds[i] < 0) {
			printf("1");
			return 0;
		}
	std::cout << kill;
}

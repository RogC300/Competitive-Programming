/*
 * 10137 - The Trip.cpp
 */
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

int main() {
	double avg, negative_sum, positive_sum, input;
	int num_people;
	std::vector<double> people;

	while (std::cin >> num_people && num_people != 0) {
		avg = 0, people.clear();
		negative_sum = positive_sum = 0;

		for (int i = 0; i < num_people; i++)
			std::cin >> input, people.push_back(input), avg += input;
		avg /= num_people;
		for (int i = 0; i < num_people; i++)
			if (people[i] > avg)
				positive_sum += (double) (long) ((people[i] - avg) * 100) / 100;
			else
				negative_sum -= (double) (long) ((people[i] - avg) * 100) / 100;

		printf("$%.2lf\n", std::max(negative_sum, positive_sum));
	}
}

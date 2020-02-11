/*
 * A Question of Ingestion.cpp
 *
 *      Author: tempo
 */
#include <iostream>

int state[101][20000], courses[101], numOfCourses, calories;

int solve(int capacity, int courseIndex, int prevCapacity) {
	if (courseIndex >= numOfCourses)
		return 0;

	if (state[courseIndex][capacity] == 0) {
		int caloriesIfEat = std::min(courses[courseIndex], capacity);

		state[courseIndex][capacity] = std::max(
				(solve(capacity * 2 / 3, courseIndex + 1, capacity)
						+ caloriesIfEat),
				std::max(solve(prevCapacity, courseIndex + 1, capacity),
						solve(calories, courseIndex + 2, capacity)));
	}
	return state[courseIndex][capacity];
}

int main() {
	scanf("%d %d", numOfCourses, calories);

	for (int i = 0; i < numOfCourses; i++)
		std::cin >> courses[i];

	std::cout << solve(calories, 0, calories);
}

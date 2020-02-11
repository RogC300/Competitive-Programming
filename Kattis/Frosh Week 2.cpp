/*
 * Frosh Week.cpp
 *
 *      Author: tempo
 */
// Problem ID froshweek2
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int amountTasks, amountNoMusic, tasksCompleted = 0;
	scanf("%d %d", &amountTasks, &amountNoMusic);
	std::vector<int> tasks(amountTasks), noMusic(amountNoMusic);
	for (int i = 0; i < amountTasks; i++)
		scanf("%d", &tasks[i]);
	for (int i = 0; i < amountNoMusic; i++)
		scanf("%d", &noMusic[i]);

	std::sort(tasks.rbegin(), tasks.rend());
	std::sort(noMusic.rbegin(), noMusic.rend());

	int taskIndex = 0, noIndex = 0;

	while (taskIndex < amountTasks && noIndex < amountNoMusic) {
		if (tasks[taskIndex] <= noMusic[noIndex])
			tasksCompleted++, noIndex++;
		taskIndex++;
	}

	printf("%d", tasksCompleted);
}

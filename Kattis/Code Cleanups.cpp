/*
 * Code Cleanups.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>

int main() {
	int n, score = 0, currPushed = 0, index = 0, answer = 0;
	scanf("%d", &n);
	std::vector<int> times(n);
	for (int i = 0; i < n; i++)
		std::cin >> times[i];

	for (int i = 1; i <= 400; i++) {
		if (i == times[index]) {
			currPushed++;
			index++;
		}
		if (score + currPushed >= 20) {
			answer++;
			currPushed = 0;
			score = 0;
		}
		score += currPushed;
	}

	std::cout << answer;

}


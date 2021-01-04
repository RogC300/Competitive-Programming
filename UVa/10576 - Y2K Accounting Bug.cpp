/*
 * 10576 - Y2K Accounting Bug.cpp
 */
#include <iostream>

int max, surplus, deficit;

bool is_valid(int arr[]) {
	for (int i = 0, sum; i < 8; i++) {
		sum = 0;
		for (int j = i; j < (i + 5); j++)
			sum += arr[j];
		if (sum >= 0)
			return false;
	}
	return true;
}

int find_sum(int arr[]) {
	int sum = 0;
	for (int i = 0; i < 12; i++)
		sum += arr[i];
	return sum;
}

void dfs(int months[], int index) {
	if (index == 12) {
		if (is_valid(months) && find_sum(months) > max)
			max = find_sum(months);
	} else {
		months[index] = surplus;
		dfs(months, index + 1);
		months[index] = deficit;
		dfs(months, index + 1);
	}
}

int main() {
	while (std::cin >> surplus >> deficit) {
		deficit *= -1;
		max = 0;
		int months[12];
		dfs(months, 0);
		if (max == 0)
			printf("Deficit\n");
		else
			printf("%d\n", max);
	}
}

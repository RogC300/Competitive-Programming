/*
 * 574 - Sum It Up.cpp
 */
#include <iostream>
#include <vector>
#include <string.h>

int numbers[1005], path[1005], target, n;
bool used[1005] = { false }, answer = false;
std::vector<std::vector<int>> solutions;

void dfs(int index, int sum, int list_index) {
	if (sum == target) {
		answer = true;
		std::vector<int> sol;
		for (int i = 0; i < index; i++)
			sol.push_back(path[i]);
		for (auto i : solutions)
			if (i == sol)
				return;
		solutions.push_back(sol);
		return;
	}
	if (index == n || sum > target)
		return;

	for (int i = list_index; i < n; i++)
		if (!used[i]) {
			path[index] = numbers[i];
			used[i] = true;
			dfs(index + 1, sum + numbers[i], i);
			used[i] = false;
		}
}

void print_vector(std::vector<int> v) {
	for (int i = 0; i < (int) v.size(); i++)
		std::cout << v[i] << (i == (int) v.size() - 1 ? "\n" : "+");
}

int main() {
	while (scanf("%d %d", &target, &n) && target != 0 && n != 0) {
		answer = false;
		memset(used, false, sizeof(used));
		solutions.clear();
		for (int i = 0; i < n; i++)
			std::cin >> numbers[i];
		printf("Sums of %d:\n", target);
		dfs(0, 0, 0);
		for (auto i : solutions)
			print_vector(i);
		if (answer == false)
			puts("NONE");
	}
}

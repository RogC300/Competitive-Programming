/*
 * 10954 - Add All.cpp
 */
#include <iostream>
#include <queue>

int main() {
	while (true) {
		int amountNum, sum = 0;
		std::cin >> amountNum;
		if (amountNum == 0)
			break;
		std::priority_queue<int, std::vector<int>, std::greater<int>> nums;
		for (int i = 0, temp; i < amountNum; i++) {
			std::cin >> temp;
			nums.push(temp);
		}
		while (nums.size() != 1) {
			int top = nums.top();
			nums.pop();
			int top2 = nums.top();
			nums.pop();
			int composite = top + top2;
			sum += composite;
			nums.push(composite);
		}
		printf("%d\n", sum);
	}
}

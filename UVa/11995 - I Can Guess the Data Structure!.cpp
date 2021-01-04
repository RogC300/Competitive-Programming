/*
 * 11995 - I Can Guess the Data Structure!.cpp
 */
#include <iostream>
#include <queue>
#include <stack>

int main() {
	int input;
	while (std::cin >> input) {
		bool stackPossible = true, queuePossible = true,
				priorityPossible = true;
		std::stack<int> stack;
		std::queue<int> queue;
		std::priority_queue<int> priority;

		while (input--) {
			int first, second;
			std::cin >> first >> second;
			switch (first) {
			case 1:
				if (stackPossible)
					stack.push(second);
				if (queuePossible)
					queue.push(second);
				if (priorityPossible)
					priority.push(second);
				break;
			case 2:
				if (stackPossible) {
					if (stack.empty() || stack.top() != second)
						stackPossible = false;
					else
						stack.pop();
				}
				if (queuePossible) {
					if (queue.empty() || queue.front() != second)
						queuePossible = false;
					else
						queue.pop();
				}
				if (priorityPossible) {
					if (priority.empty() || priority.top() != second)
						priorityPossible = false;
					else
						priority.pop();
				}
				break;
			}
		}
		if ((stackPossible && queuePossible)
				|| (stackPossible && priorityPossible)
				|| (priorityPossible && queuePossible))
			puts("not sure");
		else if (!stackPossible && !queuePossible && !priorityPossible)
			puts("impossible");
		else if (stackPossible)
			puts("stack");
		else if (queuePossible)
			puts("queue");
		else
			puts("priority queue");
	}
}

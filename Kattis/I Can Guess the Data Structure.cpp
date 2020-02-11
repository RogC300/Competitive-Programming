/*
 * I Can Guess the Data Structure.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <stack>
#include <queue>

int main(){
	int n;
	while (std::cin >> n){
	std::stack <int> s;
	std::queue <int> q;
	std::priority_queue <int> p;
	bool a = false, b = false, c = false;
	bool first = true;
	for (int i = 0; i < n; i++){
		int commandNum, command;
		std::cin >> commandNum >> command;
		if (first == true && commandNum == 2){
			a = true;
			b = true;
			c = true;
			break;
		}
		first = false;
		if (commandNum == 1){
			s.push(command);
			q.push(command);
			p.push(command);
		}
		else {
			if (s.size() == 0) a = true;
			if (q.size() == 0) b = true;
			if (p.size() == 0) c = true;

			if (a == false && s.top() != command) a = true;
			if (a == false) s.pop();
			if (b == false && q.front() != command) b = true;
			if (b == false) q.pop();
			if (c == false && p.top() != command) c = true;
			if (c == false) p.pop();
		}

	}
	int count = 0;
	if (a == false){
		count++;
	}
	if (b == false){
		count++;
	}
	if (c == false){
		count++;
	}
	if (count == 0) std::cout << "impossible\n";
	if (count == 1) {
		if (a == false) std::cout << "stack\n";
		if (b == false) std::cout << "queue\n";
		if (c == false) std::cout << "priority queue\n";
	}
	if (count > 1) std::cout << "not sure\n";

	}
}

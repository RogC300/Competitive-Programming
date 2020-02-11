/*
 * 4 thought.cpp
 */
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

std::map<int, std::string> m;

int evaluate(int a, int b, char o) {
	switch (o) {
	case '*':
		return a * b;
		break;
	case '/':
		return a / b;
		break;
	case '+':
		return a + b;
		break;
	default:
		return a - b;
	}
}

std::vector<int> eq;
void all_possible(std::string ops) {
	if (ops.length() == 3) {
		std::string out;
		out = std::string("4 ") + ops[0] + " 4 " + ops[1] + " 4 " + ops[2]
				+ " 4 = ";
		eq.assign(4, 4);
		for (int i = 0; i < (int) ops.length(); i++)
			if (ops[i] == '*' || ops[i] == '/') {
				eq[i] = evaluate(eq[i], eq[i + 1], ops[i]);
				eq.erase(eq.begin() + i + 1), ops.erase(i, 1), i--;
			}
		for (int i = 0; i < (int) ops.length(); i++) {
			eq[i] = evaluate(eq[i], eq[i + 1], ops[i]);
			eq.erase(eq.begin() + i + 1), ops.erase(i, 1), i--;
		}
		out += std::to_string(eq[0]);
		m[eq[0]] = out;
		return;
	}
	all_possible(ops + "+");
	all_possible(ops + "-");
	all_possible(ops + "*");
	all_possible(ops + "/");
}

int main() {
	all_possible("");
	int tc, num;
	std::cin >> tc;

	while (tc--) {
		std::cin >> num;
		if (m.find(num) == m.end())
			puts("no solution");
		else
			std::cout << m[num] << "\n";
	}
}

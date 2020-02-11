/*
 * Secure Doors.cpp
 */
#include <unordered_set>
#include <iostream>

int main() {
	int n;
	scanf("%d", &n);
	std::string name, cmd;
	std::unordered_set<std::string> set;

	while (n--) {
		std::cin >> cmd >> name;
		if (cmd == "entry") {
			if (set.find(name) != set.end())
				std::cout << name << " entered (ANOMALY)\n";
			else
				std::cout << name << " entered\n", set.insert(name);
		} else {
			if (set.find(name) != set.end())
				std::cout << name << " exited\n", set.erase(name);
			else
				std::cout << name << " exited (ANOMALY)\n";
		}
	}
}

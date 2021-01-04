/*
 * 793 - Network Connections.cpp
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class disjointSet {
public:
	std::vector<int> computers;
	disjointSet(int size) {
		computers.resize(size + 1);
		for (int i = 0; i <= size; i++)
			computers[i] = -1;
	}
	void make_set(int v) {
		if (computers[v] == -1)
			computers[v] = v;
	}
	int find_set(int v) {
		if (computers[v] == v)
			return v;
		return (find_set(computers[v]));
	}
	void union_sets(int a, int b) {
		a = find_set(a), b = find_set(b);
		computers[a] = b;
	}
};

int main() {
	int cases;
	bool blank = false;
	std::cin >> cases;
	while (cases--) {
		std::string command, trash;
		int numComputers, right = 0, wrong = 0;
		std::cin >> numComputers;
		getline(std::cin, trash);
		disjointSet network(numComputers);
		while (getline(std::cin, command)) {
			if (command.length() == 0)
				break;
			std::stringstream in(command);
			int a, b;
			char c;
			in >> c;
			in >> a;
			in >> b;
			network.make_set(a), network.make_set(b);
			if (command[0] == 'c')
				network.union_sets(a, b);
			if (command[0] == 'q') {
				if (network.find_set(a) == network.find_set(b))
					right++;
				else
					wrong++;
			}
		}
		if (blank)
			puts("");
		blank = true;
		printf("%d,%d\n", right, wrong);
	}
}

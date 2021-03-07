/*
 * 11503 - Virtual Friends.cpp
 */
#include <iostream>
#include <map>

class ds {
public:
	std::map<std::string, std::string> parents;
	std::map<std::string, int> size;

	void make_set(std::string v) {
		parents[v] = v;
		size[v] = 1;
	}
	std::string find_set(std::string v) {
		if (parents[v] == v)
			return v;
		return parents[v] = find_set(parents[v]);
	}
	int union_sets(std::string a, std::string b) {
		if (parents.find(a) == parents.end())
			make_set(a);
		if (parents.find(b) == parents.end())
			make_set(b);
		a = find_set(a);
		b = find_set(b);
		if (a != b) {
			if (size[a] > size[b])
				std::swap(a, b);
			parents[a] = b;
			size[b] += size[a];
			return size[b];
		} else
			return size[a];
	}
};

int main() {
	int connections, cases;
	std::cin >> cases;
	while (cases--) {
		ds net;
		std::cin >> connections;
		while (connections--) {
			std::string a, b;
			std::cin >> a >> b;
			std::cout << net.union_sets(a, b) << std::endl;
		}
	}
}

/*
 * 10608 - Friends.cpp
 */
#include <iostream>
#include <vector>

class ds {
public:
	std::vector<int> parents, size;

	ds(int size) {
		size += 1;
		parents.resize(size);
		this->size.resize(size);
		for (int i = 0; i < size; i++)
			parents[i] = -1, this->size[i] = 1;
	}

	void make_set(int v) {
		parents[v] = v;
	}

	int find_set(int v) {
		if (parents[v] == -1)
			return -1;
		if (parents[v] == v)
			return v;
		return find_set(parents[v]);
	}
	void union_sets(int a, int b) {
		if (find_set(a) == -1)
			make_set(a);
		if (find_set(b) == -1)
			make_set(b);
		a = find_set(a);
		b = find_set(b);
		if (a != b) {
			if (size[a] > size[b])
				std::swap(a, b);
			parents[a] = b;
			size[b] += size[a];
		}
	}
	int largest_set() {
		int largest = 0;
		for (int i = 0; i < (int) size.size(); i++)
			largest = std::max(size[i], largest);
		return largest;
	}
};

int main() {
	int cases;
	std::cin >> cases;
	while (cases--) {
		int people, pairs;
		std::cin >> people >> pairs;
		ds net(people);
		for (int i = 0, a, b; i < pairs; i++) {
			std::cin >> a >> b;
			net.union_sets(a, b);
		}
		std::cout << net.largest_set() << std::endl;
	}
}

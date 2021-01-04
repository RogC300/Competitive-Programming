/*
 * 11849 - CD.cpp
 */
#include <iostream>
#include <set>

int main() {
	int jack, jill;
	while (std::cin >> jack >> jill) {
		if (jack == 0 && jill == 0)
			break;
		int count = 0;
		std::set<int> CD;
		for (int i = 0, Disk; i < jack + jill; i++) {
			std::cin >> Disk;
			std::set<int>::iterator d = CD.find(Disk);
			if (d != CD.end())
				count++;
			CD.insert(Disk);
		}
		std::cout << count << std::endl;
	}
}

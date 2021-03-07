/*
 * 1237 - Expert Enough.cpp
 */
#include <iostream>
#include <map>
#include <vector>

int main() {
	int c;
	std::cin >> c;
	while (c--) {
		std::map<std::string, std::pair<int, int>> m;
		int r, p;
		std::cin >> r;
		while (r--) {
			std::string man;
			int a, b;
			std::cin >> man >> a >> b;
			m[man].first = a;
			m[man].second = b;
		}
		std::cin >> p;
		while (p--) {
			int x;
			std::vector<std::string> cars;
			std::cin >> x;
			for (auto& it : m)
				if (x <= it.second.second && x >= it.second.first)
					cars.push_back(it.first);
			if (cars.size() == 0 || cars.size() > 1)
				puts("UNDETERMINED");
			else
				std::cout << cars[0] << std::endl;
		}
		if (c)
			puts("");
	}
}

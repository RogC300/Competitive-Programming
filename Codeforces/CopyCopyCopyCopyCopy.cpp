/*
 * CopyCopyCopyCopyCopy.cpp
 */
#include <iostream>
#include <set>

int main() {
	int n, tc;
	std::cin >> tc;
	std::set<int> s;

	while (tc--) {
		std::cin >> n, s.clear();
		for (int i = 0, x; i < n; i++)
			std::cin >> x, s.insert(x);
		std::cout << s.size() << "\n";
	}
}

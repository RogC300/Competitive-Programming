/*
 * 441 - Lotto.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int n;
	bool st = false;
	while (std::cin >> n && n != 0) {
		std::vector<int> s;
		for (int i = 0, x; i < n; i++)
			std::cin >> x, s.push_back(x);
		st == false ? st = true : puts("");
		for (int a = 0; a < n; a++)
			for (int b = a + 1; b < n; b++)
				for (int c = b + 1; c < n; c++)
					for (int d = c + 1; d < n; d++)
						for (int e = d + 1; e < n; e++)
							for (int f = e + 1; f < n; f++)
								printf("%d %d %d %d %d %d\n", s[a], s[b], s[c],
										s[d], s[e], s[f]);
	}
}

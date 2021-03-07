/*
 * 11723 - Numbering Roads.cpp
 */
#include <iostream>
#include <cmath>

int main() {
	int tc = 1;

	int r, n, a_req;
	while (std::cin >> r >> n && (r != 0 || n != 0)) {
		if ((r - n) % n == 0)
			a_req = (r - n) / n;
		else
			a_req = ceil((double) (r - n) / n);
		if (a_req <= 26)
			printf("Case %d: %d\n", tc++, a_req);
		else
			printf("Case %d: impossible\n", tc++);
	}
}

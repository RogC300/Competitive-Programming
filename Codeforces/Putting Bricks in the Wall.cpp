/*
 * Putting Bricks in the Wall.cpp
 */
#include <iostream>

int main() {
	int n, tc;

	std::cin >> tc;

	while (tc--) {

		std::cin >> n;

		std::string v[n];

		for (int i = 0; i < n; i++)
			std::cin >> v[i];

		int s = 0, f = 0, s_parity, f_parity;

		s += v[0][1] - '0' + v[1][0] - '0';
		f += v[n - 2][n - 1] - '0' + v[n - 1][n - 2] - '0';

		if ((s == 0 && f == 2) || (s == 2 && f == 0)) {
			std::cout << "0\n";
			continue;
		}

		s = (s == 1 ? -1 : 0), f = (f == 1 ? -1 : 0);
		s_parity = (v[0][1] - '0'), f_parity = (v[n - 2][n - 1] - '0');

		int out_a, out_b;
		if (s == 0) {
			out_a = n - 1, out_b = n;
			if (f == -1) {
				if (v[n - 1][n - 2] - '0' == s_parity)
					std::swap(out_a, out_b);
				printf("1\n%d %d\n", out_a, out_b);
			} else
				printf("2\n%d %d\n%d %d\n", out_a, out_b, out_b, out_a);
		} else if (f == 0) {
			out_a = 1, out_b = 2;
			if (s == -1) {
				if (v[1][0] - '0' == f_parity)
					std::swap(out_a, out_b);
				printf("1\n%d %d\n", out_a, out_b);
			} else
				printf("2\n%d %d\n%d %d\n", out_a, out_b, out_b, out_a);
		} else {
			printf("2\n%d %d\n", 1, 2);

			if (v[n - 1][n - 2] == v[0][1])
				printf("%d %d\n", n - 1, n);
			else
				printf("%d %d\n", n, n - 1);
		}
	}
}

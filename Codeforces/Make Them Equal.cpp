/*
 * Make Them Equal.cpp
 */
#include <iostream>
#include <vector>

int mod(int a, int b) {
	if (a % b == 0)
		return b;
	return a % b;
}

int main() {
	int tc, n, sum, avg;
	std::vector<int> v;

	std::cin >> tc;

	while (tc--) {

		std::cin >> n, sum = 0, v.resize(n);

		for (int i = 0; i < n; i++)
			std::cin >> v[i], sum += v[i];

		if (sum % n != 0) {
			std::cout << "-1\n";
			continue;
		}
		avg = sum / n;

		std::cout << (n - 1) * 3 << "\n";

		for (int i = 1; i < n; i++) {
			printf("%d %d %d\n", 1, (i + 1), (i + 1) - mod(v[i], i + 1));
			v[0] -= (i + 1) - mod(v[i], i + 1);
			v[i] += (i + 1) - mod(v[i], i + 1);

			printf("%d %d %d\n", (i + 1), 1, (v[i] / (i + 1)));
			v[0] += v[i], v[i] = 0;
		}

		for (int i = 1; i < n; i++) {
			printf("%d %d %d\n", 1, (i + 1), avg);
			v[0] -= avg, v[i] = avg;
		}
		//		for (auto i : v)
		//			std::cout << i << " ";
		//		puts ("");
	}
}

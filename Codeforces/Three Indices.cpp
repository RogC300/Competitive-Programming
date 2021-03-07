/*
 * Three Indices.cpp
 */
#include <iostream>
#include <vector>

int main() {
	int n, tc;
	std::vector<int> v;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n, v.resize(n);

		for (int i = 0; i < n; i++)
			std::cin >> v[i];
		int start = -1, mid = -1, end = -1;

		for (int i = 0; i < n; i++) {
			if (v[i] < v[i + 1] && start == -1)
				start = i;
			if (v[i] > v[i + 1] && start != -1 && mid == -1)
				mid = i;
			if (mid != -1 && v[i] < v[mid]) {
				end = i;
				break;
			}
		}
		if (mid == -1 || start == -1 || end == -1)
			std::cout << "NO\n";
		else
			printf("YES\n%d %d %d\n", start + 1, mid + 1, end + 1);
	}
}

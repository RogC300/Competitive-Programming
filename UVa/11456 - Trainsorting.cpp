/*
 * 11456 - Trainsorting.cpp
 */
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int tc;
	std::cin >> tc;
	int n;
	std::vector<int> input;
	while (tc--) {
		std::cin >> n;
		input.resize(n);
		std::vector<int> inc(n, 1), dec(n, 1);

		for (int i = 0; i < n; i++)
			std::cin >> input[i];
		std::reverse(input.begin(), input.end());

		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
				if (input[j] < input[i])
					inc[i] = std::max(inc[i], inc[j] + 1);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
				if (input[j] > input[i])
					dec[i] = std::max(dec[i], dec[j] + 1);
		int max = 0;
		for (int i = 0; i < n; i++)
			max = std::max(max, dec[i] + inc[i] - 1);
		std::cout << max << std::endl;
	}
}

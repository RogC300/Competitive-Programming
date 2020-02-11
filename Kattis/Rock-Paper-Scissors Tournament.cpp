/*
 * Rock-Paper-Scissors Tournament.cpp
 */
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
	std::vector<int> wins, total;
	int n, k;
	std::string in_a, in_b;

	while (std::cin >> n && n != 0) {
		std::cin >> k, total.assign(n, k * (n - 1)), wins.assign(n, 0);

		for (int i = 0, a, b; i < k * n * (n - 1) / 2; i++) {
			std::cin >> a >> in_a >> b >> in_b, a--, b--;

			if (in_a == in_b) {
				total[a]--, total[b]--;
				continue;
			}
			if (in_a > in_b)
				std::swap(in_a, in_b), std::swap(a, b);

//		std::cout << in_a << "  " << in_b << " " << a << " " << b << "\n" ;
			if (in_a == "paper")
				in_b == "rock" ? wins[a]++ : wins[b]++;
			if (in_a == "rock")
				wins[a]++;
		}
		std::cout << std::fixed << std::setprecision(3);
		for (int i = 0; i < n; i++) {
			if (total[i] == 0)
				puts("-");
			else
				std::cout << (double) wins[i] / total[i] << "\n";
		}
		puts("");
	}
}

/*
 * The Owl and the Fox.cpp
 */
#include <iostream>

int find_sum(int n) {
	int sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main() {
	int n;
	std::cin >> n;
	while (n--) {
		int a;
		std::cin >> a;
		int s = find_sum(a) - 1;
		for (int i = a; i >= 0; i--)
			if (find_sum(i) == s) {
				std::cout << i << std::endl;
				break;
			}
	}

}


/*
 * 324 - Factorial Frequencies.cpp
 */
#include <iostream>
#include <vector>

std::vector<int> num, digits;
int n;

void output() {
	printf("%d! --\n", n);
	printf("   (0)   %d    (1)   %d    (2)   %d    (3)   %d    (4)   %d\n",
			digits[0], digits[1], digits[2], digits[3], digits[4]);
	printf("   (5)   %d    (6)   %d    (7)    %d    (8)   %d    (9)   %d\n",
			digits[5], digits[6], digits[7], digits[8], digits[9]);
	/*
	 100! --
	 (0)   30    (1)   15    (2)   19    (3)   10    (4)   10
	 (5)   14    (6)   19    (7)    7    (8)   14    (9)   20
	 */
}

void multiply(int mult) {
	for (int i = 0, carry = 0, current; i < (int) num.size() || carry; i++) {
		current = num[i] * mult + carry, num[i] = current % 10;
		current /= 10, carry = current;
		if (carry)
			num.push_back(0);
	}
	// trim
	while (!num.empty() && !num.back())
		num.pop_back();
}

int main() {
	while (std::cin >> n && n != 0) {
		num.clear(), num.push_back(1);
		digits.clear(), digits.assign(10, 0);

		for (int i = 1; i <= n; i++)
			multiply(i);
		for (int i = 0; i < (int) num.size(); i++)
			digits[num[i]]++;

		output();
	}
}

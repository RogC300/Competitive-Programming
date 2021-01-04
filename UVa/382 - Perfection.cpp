/*
 * 382 - Perfection.cpp
 */
#include <iostream>
#include <iomanip>
#include <vector>

int sum_divisor(int n) {
	int sum = 0;
	for (int i = 1; i < n; i++)
		if (n % i == 0)
			sum += i;
	return sum;
}

int main() {
	std::vector<std::pair<int, std::string>> nums;

	int num;
	while (std::cin >> num && num != 0) {
		int sum = sum_divisor(num);
		if (sum == num)
			nums.push_back( { num, "PERFECT" });
		else if (num > sum)
			nums.push_back( { num, "DEFICIENT" });
		else
			nums.push_back( { num, "ABUNDANT" });
	}

	puts("PERFECTION OUTPUT");
	for (int i = 0; i < (int) nums.size(); i++)
		std::cout << std::setw(5) << nums[i].first << "  " << nums[i].second
				<< "\n";
	puts ("END OF OUTPUT");
}

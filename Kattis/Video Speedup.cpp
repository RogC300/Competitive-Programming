/*
 * Video Speedup.cpp
 */
#include <iostream>
#include <iomanip>

int main() {
	int number_speedups, percent_per_speedup, final_time;
	std::cin >> number_speedups >> percent_per_speedup >> final_time;
	float percent = 100, original_time = 0;
	int speedup_times[number_speedups + 1];
	speedup_times[0] = 0;
	for (int i = 1; i <= number_speedups; i++) {
		std::cin >> speedup_times[i];
		original_time += (speedup_times[i] - speedup_times[i - 1]) * percent
				/ 100;
		percent += percent_per_speedup;
	}
	original_time += (final_time - speedup_times[number_speedups]) * percent
			/ 100;
	std::cout << std::fixed << std::setprecision(6) << original_time;
}

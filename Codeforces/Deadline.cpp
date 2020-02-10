/*
 * Deadline.cpp
 */
#include <iostream>
#include <cmath>

int main() {
	int deadline, run, sum, tc;
	double x;
	bool complete;

	std::cin >> tc;

	while (tc--) {
		std::cin >> deadline >> run;
		complete = false;
		for (int i = 0; i < deadline && !complete; i++) {
			x = run / (i + 1.0), sum = ceil(x) + i;
			if (sum <= deadline)
				complete = true;
		}
		std::cout << (complete ? "YES\n" : "NO\n");
	}
}

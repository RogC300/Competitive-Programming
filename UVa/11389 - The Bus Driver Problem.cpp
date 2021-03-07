/*
 * 11389 - The Bus Driver Problem.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

void v_print(std::vector<int> v) {
	for (int i = 0; i < (int) v.size(); i++)
		std::cout << v[i] << (i == (int) v.size() - 1 ? "\n" : " ");
	puts("");
}

int main() {
	int routes = -1, until_overtime = -1, overtime_pay = -1, total_overtime = 0;
	std::vector<int> morning, evening;
	while (std::cin >> routes >> until_overtime >> overtime_pay && routes != 0
			&& until_overtime != 0 && overtime_pay != 0) {
		total_overtime = 0, morning.clear(), evening.clear();
		for (int i = 0, distance; i < routes; i++)
			std::cin >> distance, morning.push_back(distance);
		for (int i = 0, distance; i < routes; i++)
			std::cin >> distance, evening.push_back(distance);
		std::sort(morning.rbegin(), morning.rend()), std::sort(evening.begin(),
				evening.end());
//		v_print (morning), v_print(evening);

		for (int i = 0; i < routes; i++) {
			auto lowest = std::upper_bound(evening.begin(), evening.end(),
					until_overtime - morning[i]);
			if (lowest != evening.begin())
				lowest--;
			total_overtime += (
					*lowest + morning[i] - until_overtime > 0 ?
							*lowest + morning[i] - until_overtime : 0);
//			printf ("%d %d\n", *lowest, morning[i]);
			evening.erase(lowest);
		}
		std::cout << total_overtime * overtime_pay << std::endl;
	}
}

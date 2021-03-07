/*
 * Hired Help.cpp
 */
#include<iostream>
#include <map>

int main() {
	int n, k;
	std::cin >> n >> k;
	std::map<int, int> m;

	for (int i = 0, in; i < n; i++)
		std::cin >> in, m[in]++;
	int work = 0, count;
//	std::cout << "asd\n";
	while (1) {
		count = 0;
		for (int cur_time = 0; count < k; count++) {
			auto itu = m.upper_bound(cur_time);
			if (itu == m.end())
				break;
//			std::cout << itu->first << " " << itu->second << "\n";


			m[itu->first]--;
			cur_time++;
			if (m[itu->first] == 0)
				m.erase (itu);
		}
//		puts ("");
		if (count != k)
			break;
		work++;
	}
	std::cout << work;

}


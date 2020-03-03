/*
 * Books Exchange.cpp
 */
#include <iostream>
#include <set>
#include <vector>
#include <map>

int main() {
	int n, tc;
	std::vector<int> kids, index;
	std::map<int, int> m;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n;
		index.resize(n), kids.resize(n), m.clear();

		for (int i = 0; i < n; i++)
			std::cin >> kids[i], kids[i]--;

		for (int i = 0, temp, count = 0, t; i < n; i++) {
			if (kids[i] == -1)
				continue;
			temp = kids[i], kids[i] = -1;
			index[i] = count;
			while (temp != i) {
				index[temp] = count;
				t = temp;
				temp = kids[temp];
				kids[t] = -1;
			}
			count++;
		}

//		for (int i = 0; i < n; i++)
//			std::cout << index[i] << " ";
//		puts("");
		for (int i = 0; i < n; i++)
			m[index[i]]++;

		for (int i = 0; i < n; i++)
			std::cout << m[index[i]] << " ";
		puts("");
	}
}

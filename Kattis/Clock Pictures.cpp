/*
 * Clock Pictures.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void pv(std::vector<int> v) {
	for (int i = 0; i < (int) v.size(); i++)
		std::cout << v[i] << (i == (int) v.size() - 1 ? "\n" : " ");
	puts("");
}

bool check(std::vector<int> a, std::vector<int> b) {
	b.insert(b.end(), b.begin(), b.end());
	int size = a.size();
	int lps[size], len = 0, index = 1;
	lps[0] = 0;
	while (index < size) {
		if (a[index] == a[len]) {
			++len;
			lps[index] = len;
			index++;
		} else {
			if (len != 0)
				len = lps[len - 1];
			else
				lps[index] = 0, index++;
		}
	}

	int i = 0, j = 0, b_size = b.size();

	while (i < b_size) {
		if (a[j] == b[i])
			i++, j++;

		if (j == size)
			return true;
		else if (i < b_size && b[i] != a[j])
			j != 0 ? j = lps[j - 1] : i++;
	}
	return false;
}

int main() {
	int n;
	std::vector<int> clock_a, clock_b, a, b;
	std::set<int> check_a, check_b;
	std::cin >> n;

	for (int i = 0, a; i < n; i++)
		std::cin >> a, clock_a.push_back(a);
	for (int i = 0, a; i < n; i++)
		std::cin >> a, clock_b.push_back(a);

	std::sort(clock_a.begin(), clock_a.end());
	std::sort(clock_b.begin(), clock_b.end());
	clock_a.push_back(360000 + clock_a[0]);
	clock_b.push_back(360000 + clock_b[0]);

	for (int i = 1; i < (int) clock_a.size(); i++) {
		int t = clock_a[i] - clock_a[i - 1];
		a.push_back(t), check_a.insert(t);
	}

	for (int i = 1; i < (int) clock_b.size(); i++) {
		int t = clock_b[i] - clock_b[i - 1];
		b.push_back(t), check_b.insert(t);
	}

//	pv (clock_a), pv(clock_b);
//	for (auto i : a)
//		std::cout << i << " ";
//	puts ("");
//	for (auto i : b_for)
//		std::cout << i << " ";

	if (check_a == check_b && check(a, b))
		std::cout << "possible";
	else
		std::cout << "impossible";
}

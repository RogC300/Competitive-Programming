/*
 * Pair of Topics.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

typedef long long int ll;

ll combo(ll n) {
	if (n == 1)
		return 0;
	return n * (n - 1) / 2;
}

int main() {
	int n;
	std::vector<std::pair<int, int>> in;
	std::vector<int> teacher, student;

	std::cin >> n, in.resize(n);

	for (int i = 0; i < n; i++)
		std::cin >> in[i].first;
	for (int i = 0; i < n; i++)
		std::cin >> in[i].second;

	for (int i = 0, t; i < n; i++) {
		t = in[i].first;
		in[i].first = std::max(in[i].first - in[i].second, 0);
		in[i].second = std::max(in[i].second - t, 0);
	}

	for (int i = 0; i < n; i++) {
		if (in[i].first == 0 && in[i].second == 0)
			student.push_back(0);
		else if (in[i].first == 0)
			student.push_back(in[i].second);
		else
			teacher.push_back(in[i].first);
	}

	std::sort(student.begin(), student.end());
	if (teacher.size())
		std::sort(teacher.begin(), teacher.end());

	ll sum = combo(teacher.size());

	for (int i = 0; i < (int) teacher.size(); i++)
		sum += std::lower_bound(student.begin(), student.end(), teacher[i])
				- student.begin();
	std::cout << sum;
}

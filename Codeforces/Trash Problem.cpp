/*
 * Trash Problem.cpp
 */
#include <iostream>
#include <set>
#include <cstdio>

std::multiset<int> len;
std::set<int> pos;

int get() {
	if (len.empty())
		return 0;
	return *pos.rbegin() - *pos.begin() - *len.rbegin();
}

void remove(int p) {
	auto it = pos.find(p);
	int prev = -1, next = -1;
	if (it != pos.begin()) {
		it--;
		len.erase(len.find(p - *it)), prev = *it;
		it++;
	}
	it++;
	if (it != pos.end())
		len.erase(len.find(*it - p)), next = *it;
	pos.erase(p);
	if (prev != -1 && next != -1)
		len.insert(next - prev);
}

void add(int p) {
	pos.insert(p);
	auto it = pos.find(p);
	int prev = -1, next = -1;

	if (it != pos.begin()) {
		it--;
		len.insert(p - *it), prev = *it;
		it++;
	}
	it++;
	if (it != pos.end())
		len.insert(*it - p), next = *it;

	if (prev != -1 && next != -1)
		len.erase(len.find(next - prev));
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int num_pile, q;

	std::cin >> num_pile >> q;

	for (int i = 0, in; i < num_pile; i++)
		std::cin >> in, add(in);
	std::cout << get() << "\n";

	for (int i = 0, cmd, p; i < q; i++) {
		std::cin >> cmd >> p;
		cmd == 0 ? remove(p) : add(p);
		std::cout << get() << "\n";
	}
}

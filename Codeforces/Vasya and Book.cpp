/*
 * 1082A - Vasya and Book.cpp
 *
 *      Author: Roger
 */
#include<iostream>
#include<algorithm>

#define inf 0x3f3f3f3f

int solve(int pages, int start, int finish, int scroll) {
	int s1, s2, num, num1, num2;

	if (abs(start - finish) % scroll == 0)
		return abs(start - finish) / scroll;

	if ((pages - start) % scroll == 0)
		s1 = (pages - start) / scroll;
	else
		s1 = (pages - start) / scroll + 1;

	if ((start - 1) % scroll == 0)
		s2 = (start - 1) / scroll;
	else
		s2 = (start - 1) / scroll + 1;

	if ((pages - finish) % scroll == 0)
		num1 = (pages - finish) / scroll + s1;
	else
		num1 = inf;

	if ((finish - 1) % scroll == 0)
		num2 = (finish - 1) / scroll + s2;
	else
		num2 = inf;

	num = std::min(num1, num2);
	if (num == inf)
		return -1;
	else
		return num;
}

int main() {
	int runs, n, d, x, y;
	std::cin >> runs;
	while (runs--) {
		std::cin >> n >> x >> y >> d;
		printf("%d\n", solve(n, x, y, d));
	}
}

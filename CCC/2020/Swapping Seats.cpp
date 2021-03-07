/*
 * Swapping Seats.cpp
 */
#include <iostream>
#include <vector>

int main() {
	std::string s;
	std::vector<int> pre_a, pre_b, pre_c;
	int len, a, b, c, ans = 1e9;

	std::cin >> s;
	s += s;
	len = s.length();

	pre_a.assign(len, 0), pre_b.assign(len, 0), pre_c.assign(len, 0);

	for (int i = 0; i < len; i++) {
		pre_a[i] = (i > 0 ? pre_a[i - 1] : 0) + (s[i] == 'A' ? 1 : 0);
		pre_b[i] = (i > 0 ? pre_b[i - 1] : 0) + (s[i] == 'B' ? 1 : 0);
		pre_c[i] = (i > 0 ? pre_c[i - 1] : 0) + (s[i] == 'C' ? 1 : 0);
	}
	a = pre_a[len / 2 - 1], b = pre_b[len / 2 - 1], c = pre_c[len / 2 - 1];

	if (a == len / 2 || b == len / 2 || c == len / 2) {
		std::cout << 0;
		return 0;
	}
	for (int i = 0, off_a, off_b, in_a, in_b; i < len / 2; i++) {
		off_a = a - (pre_a[i + a - 1] - (i > 0 ? pre_a[i - 1] : 0));
		off_b = b - (pre_b[i + a + b - 1] - (a > 0 ? pre_b[i - 1 + a] : 0));
		in_a = (pre_b[i + a - 1] - (i > 0 ? pre_b[i - 1] : 0));
		in_b = (pre_a[i + a + b - 1] - (a > 0 ? pre_a[i - 1 + a] : 0));
		ans = std::min(ans, off_a + off_b - std::min(in_a, in_b));
	}
	for (int i = 0, off_a, off_c, in_a, in_c; i < len / 2; i++) {
		off_a = a - (pre_a[i + a - 1] - (i > 0 ? pre_a[i - 1] : 0));
		off_c = c - (pre_c[i + a + c - 1] - (a > 0 ? pre_c[i - 1 + a] : 0));
		in_a = (pre_c[i + a - 1] - (i > 0 ? pre_c[i - 1] : 0));
		in_c = (pre_a[i + a + c - 1] - (a > 0 ? pre_a[i - 1 + a] : 0));
		ans = std::min(ans, off_a + off_c - std::min(in_a, in_c));
	}
	std::cout << ans;
}

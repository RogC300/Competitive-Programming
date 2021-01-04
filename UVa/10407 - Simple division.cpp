/*
 * 10407 - Simple division.cpp
 */
#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<int> vi;

/* Naive (mine)
int mod(int k, int n) {
	return ((k %= n) < 0) ? k + n : k;
}

bool check(vi v, int n) {
	int c = mod(v[0], n);
	for (int i = 0; i < (int) v.size(); i++)
		if (mod(v[i], n) != c)
			return false;
	return true;
}

int main() {
	vi v;
	int input, min, i;

	while (std::cin >> input && input != 0) {
		min = 1e9, v.clear(), v.push_back(input), i = 0;
		while (std::cin >> input && input != 0)
			v.push_back(input), (
					abs(input - v[i]) == 0 ?
							1 : min = std::min(abs(input - v[i]), min)), i++;
		min++;
		while (min-- && min != 0)
			if (check(v, min)) {
				std::cout << min << "\n";
				break;
			}
	}
}
*/
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int gcd_vec(vi v) {
	int r = v[0];
	for (int i = 1; i < (int) v.size(); i++)
		r = gcd(v[i], r);
	return r;
}

int main() {
	int input;
	vi original, v2;
	while (std::cin >> input && input != 0) {
		original.clear(), v2.clear(), original.push_back(input);

		while (std::cin >> input && input != 0)
			original.push_back(input);

		for (int i = 0; i < (int) original.size() - 1; i++)
			v2.push_back(original[i + 1] - original[i]);

		std::cout << abs(gcd_vec(v2)) << "\n";
	}
}

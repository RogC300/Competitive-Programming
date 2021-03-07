/*
 * RPG Protagonist.cpp
 */
#include <iostream>
#include <vector>

long long int max_p, min_p, max_f, min_f, cnt_s, cnt_w, s, w;

void fill(long long int p, long long int f, bool par) {
	long long int temp_p = p / s, temp_cnt = cnt_s;

	temp_p -= std::min(p / s, temp_cnt);
	temp_p = temp_p * s + (p % s);
	temp_cnt -= std::min(p / s, temp_cnt);

	long long int temp_f = f;

	if (temp_cnt > 0) {
		temp_f = f / s;
		temp_f -= std::min(f / s, temp_cnt);
		temp_f = temp_f * s + (f % s);
	}
	if (par == 0)
		min_p = temp_p, max_f = temp_f;
	else
		min_f = temp_p, max_p = temp_f;
}

long long int rem(long long int a, long long int b) {
	a -= (a % w);
	b -= (b % w);

	return std::min((a + b) / w, cnt_w);
}

long long int solve() {
	long long int p, f, max = 0;
	std::cin >> p >> f >> cnt_s >> cnt_w >> s >> w;

	if (s > w)
		std::swap(s, w), std::swap(cnt_s, cnt_w);
	if (s * cnt_s >= (p - (p % s)) + (f - (f % s)))
		return p / s + f / s;
	fill(p, f, 0), fill(f, p, 1);

//	printf ("%d %d %d %d\n", min_p, max_p, min_f, max_f);

	while (max_p >= min_p) {
		max = std::max(max, rem(max_p, min_f));
		max_p -= s, min_f += s;
	}
	return max + cnt_s;
}

int main() {
	int tc = 1;
	std::cin >> tc;

	while (tc--)
		std::cout << solve() << "\n";
}

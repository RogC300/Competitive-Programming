/*
 * Skyscrapers (hard version).cpp
 */
#include <iostream>
#include <stack>
#include <vector>

typedef long long ll;

int main() {
	ll n;
	std::vector<ll> in, min_l, min_r, l, r, out;

	std::cin >> n, in.resize(n), min_l.resize(n), min_r.resize(n);

	for (int i = 0; i < n; i++)
		std::cin >> in[i];

	std::stack<ll> s;
	for (int i = 0; i < n; i++) {
		while (s.size() && in[s.top()] >= in[i])
			s.pop();
		s.empty() ? min_l[i] = -1 : min_l[i] = s.top(), s.push(i);
	}
	while (!s.empty())
		s.pop();
	for (int i = n - 1; i >= 0; i--) {
		while (s.size() && in[s.top()] >= in[i])
			s.pop();
		s.empty() ? min_r[i] = -1 : min_r[i] = s.top(), s.push(i);
	}

	l.resize(n), r.resize(n);
	for (int i = 0; i < n; i++)
		l[i] = (min_l[i] == -1 ?
				in[i] * (i + 1) : in[i] * (i - min_l[i]) + l[min_l[i]]);
	for (int i = n - 1; i >= 0; i--)
		r[i] = (min_r[i] == -1 ?
				in[i] * (n - i) : in[i] * (min_r[i] - i) + r[min_r[i]]);

	int index;
	ll val = 0, temp;
	for (int i = 0; i < n; i++) {
		temp = r[i] + l[i] - in[i];
		if (temp > val)
			index = i, val = temp;
	}

	out.resize(n);
	ll m = 1e15;
	for (int i = index; i < n; i++)
		m = std::min(m, in[i]), out[i] = m;
	m = 1e15;
	for (int i = index; i >= 0; i--)
		m = std::min(m, in[i]), out[i] = m;

	for (auto i : out)
		std::cout << i << " ";
}

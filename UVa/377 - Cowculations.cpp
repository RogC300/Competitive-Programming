/*
 * 377 - Cowculations.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> vi;

void pv(std::vector<int> v) {
	for (int i = 0; i < (int) v.size(); i++)
		std::cout << v[i] << (i == (int) v.size() - 1 ? "\n" : " ");
	puts("");
}

vi convert(std::string s) {
	vi n;
	for (int i = 0; i < (int) s.length(); i++)
		switch (s[i]) {
		case 'V':
			n.push_back(0);
			break;
		case 'U':
			n.push_back(1);
			break;
		case 'C':
			n.push_back(2);
			break;
		case 'D':
			n.push_back(3);
			break;
		}
	return n;
}

vi add(vi a, vi b) {
	vi result;

	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());

	if (a.size() < b.size())
		for (int i = 0; i < (int) a.size() - (int) b.size(); i++)
			a.push_back(0);
	if (b.size() < a.size())
		for (int i = 0; i < (int) b.size() - (int) a.size(); i++)
			b.push_back(0);
//	pv (a), pv (b);

	int carry = 0;
	for (int i = 0, sum; i < (int) a.size(); i++) {
		sum = a[i] + b[i] + carry;
//		std::cout << a[i] << " " << b[i] << " " << carry << "\n";
		if (sum >= 4)
			carry = 1, sum -= 4;
		else
			carry = 0;
		result.push_back(sum);
	}
	if (carry == 1)
		result.push_back(1);

	std::reverse(result.begin(), result.end());
	return result;

}

vi r(vi b) {
	vi result;
	result.push_back(0);
	for (int i = 0; i < (int) b.size() - 1; i++)
		result.push_back(b[i]);
	return result;
}

vi l(vi b) {
	b.push_back(0);
	return b;
}

vi pad(vi b) {
	std::reverse(b.begin(), b.end());
	while (b.size() < 8)
		b.push_back(0);
	std::reverse(b.begin(), b.end());
	return b;
}

int main() {
	std::string a, b, c;
	vi num1, num2, final;
	char cmd;
	int tc;
	std::cin >> tc;
	puts("COWCULATIONS OUTPUT");
	while (tc--) {
		std::cin >> a >> b;
		num1 = convert(a), num2 = convert(b);

		for (int i = 0; i < 3; i++) {
			std::cin >> cmd;
			switch (cmd) {
			case 'A':
				num2 = add(num1, num2);
				break;
			case 'L':
				num2 = l(num2);
				break;
			case 'R':
				num2 = r(num2);
			}
//			pv (num2);
		}
		std::cin >> c;
		final = convert(c);
		num2 = pad(num2);
		bool same = true;
		for (int i = 0; i < 8; i++)
			if (final[i] != num2[i])
				same = false;

		if (same)
			puts("YES");
		else
			puts("NO");
//		pv(num2);
	}
	puts("END OF OUTPUT");
}

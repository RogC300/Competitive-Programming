/*
 * 443 - Humble Numbers.cpp
 */
#include <iostream>
#include <vector>
#include <set>

typedef long long ll;

ll m[4] = { 2, 3, 5, 7 };

int main() {
	std::set<ll> s;
	s.insert(1);
	auto i = s.begin();
	while (s.size() < 7000) {
		for (int j = 0; j < 4; j++)
			s.insert((*i) * m[j]);
		i++;
	}
	std::vector<ll> v(s.begin(), s.end());
	int n;
	while (std::cin >> n && n != 0) {
		printf("The %d", n);
		if (n % 10 == 1 && ((n / 10) % 10 != 1 || n < 10))
			printf("st");
		else if (n % 10 == 2 && ((n / 10) % 10 != 1 || n < 10))
			printf("nd");
		else if (n % 10 == 3 && ((n / 10) % 10 != 1 || n < 10))
			printf("rd");
		else
			printf("th");
		printf(" humble number is ");
		std::cout << v[n - 1] << ".\n";
	}

}

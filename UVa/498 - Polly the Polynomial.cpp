/*
 * 498 - Polly the Polynomial.cpp
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>

typedef long long ll;

std::vector<ll> poly;
std::string first_input;

void input_poly() {
	std::stringstream ss(first_input);
	ll n;
	while (ss >> n)
		poly.push_back(n);
	std::reverse(poly.begin(), poly.end());
}

ll evaluate(ll n) {
	ll sum = 0;
	for (int i = poly.size() - 1; i >= 0; i--) {
		ll add = pow(n, i) * poly[i];
		sum += add;
//		std::cout << n << " " << i << " " << poly[i] <<  " " << add << "\n";
	}
	return sum;
}

void input_evaluate() {
	std::string line;
	getline(std::cin, line);
	std::stringstream ss(line);
	ll n;
	bool first = false;
	while (ss >> n) {
		std::cout << (first == true ? " " : ""), first = true;
		std::cout << evaluate(n);
	}
	puts("");
}

int main() {
	while (getline(std::cin, first_input)) {
		poly.clear();
		input_poly();
		input_evaluate();
	}
}

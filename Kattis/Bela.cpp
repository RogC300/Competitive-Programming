/*
 * Bela.cpp
 */
#include <iostream>
#include <map>

int main() {
	int hands, sum = 0;
	char dom, card, suit;
	std::map<char, int> is_dom, not_dom;
	is_dom['A'] = 11, not_dom['A'] = 11;
	is_dom['K'] = 4, not_dom['K'] = 4;
	is_dom['Q'] = 3, not_dom['Q'] = 3;
	is_dom['J'] = 20, not_dom['J'] = 2;
	is_dom['T'] = 10, not_dom['T'] = 10;
	is_dom['9'] = 14, not_dom['9'] = 0;
	is_dom['8'] = 0, not_dom['8'] = 0;
	is_dom['7'] = 0, not_dom['7'] = 0;

	std::cin >> hands >> dom;
	for (int i = 0; i < hands * 4; i++) {
		std::cin >> card >> suit;
		if (suit == dom)
			sum += is_dom[card];
		else
			sum += not_dom[card];
	}
	std::cout << sum;
}

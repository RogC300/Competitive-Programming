/*
 * Parsing Hex.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool valid(char c) {
	return (c <= '9' && c >= '0') || (c <= 'F' && c >= 'A');
}

long long int to_int(std::string h) {
	std::transform(h.begin(), h.end(), h.begin(), ::toupper);
	std::reverse(h.begin(), h.end());

	long long int dec = 0, m;
	for (int i = 0; i < (int) h.length() - 2; i++) {
		h[i] >= 'A' && h[i] <= 'F' ? m = h[i] - 'A' + 10 : m = h[i] - '0';
		dec += std::pow(16, i) * m;
	}
	return dec;
}

int main() {
	std::vector<std::string> hex;
	std::string in, original;

	while (std::cin >> in) {
		hex.clear(), original = in;
		std::transform(in.begin(), in.end(), in.begin(), ::toupper);

		for (int i = 0, j; i < (int) in.length(); i++)
			if (in[i] >= '0' && in[i] <= '9' && i + 2 < (int) in.length()
					&& in[i + 1] == 'X' && valid(in[i + 2])) {
				for (j = i + 2; j < (int) in.length(); j++)
					if (!valid(in[j]))
						break;
				hex.push_back(original.substr(i, j - i));
			}
		for (auto i : hex)
			std::cout << i << " " << to_int(i) << "\n";
	}
}

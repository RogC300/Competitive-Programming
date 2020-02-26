	/*
	 * Equalizing Two Strings.cpp
	 */
	#include <iostream>
	#include <algorithm>
	#include <map>

	bool has_same_characters(std::string a, std::string b) {
		std::sort(a.begin(), a.end());
		std::sort(b.begin(), b.end());

		if (a == b)
			return true;
		return false;
	}

	int main() {
		std::string a, b;
		int length, in_a, in_b, tc;
		std::map<char, int> m1, m2;
		bool mult;

		std::cin >> tc;

		while (tc--) {
			std::cin >> length >> a >> b;
			m1.clear(), m2.clear(), in_a = in_b = 0, mult = false;

			if (!has_same_characters(a, b)) {
				std::cout << "NO\n";
				continue;
			}

			for (int i = 0; i < length; i++)
				m1[a[i]]++, m2[b[i]]++;

			for (auto i : m1)
				if (i.second > 1)
					mult = true;
			if (mult) {
				std::cout << "YES\n";
				continue;
			}

			for (int i = 0; i < length; i++)
				for (int j = 0; j < i; j++)
					in_a += a[i] > a[j], in_b += b[i] > b[j];
	//		std::cout << in_a << " " << in_b << "\n";
			if ((in_a & 1) == (in_b & 1))
				std::cout << "YES\n";
			else
				std::cout << "NO\n";
		}
	}

/*
 * Infinite Prefixes.cpp
 */
#include <iostream>
#include <algorithm>

int main() {
	int length, targ_bal, bal_n, ans, tc;
	bool inf;
	std::string s;

	std::cin >> tc;

	while (tc--) {
		std::cin >> length >> targ_bal >> s;

		bal_n = count(s.begin(), s.end(), '0'), ans = 0;
		bal_n = bal_n - (length - bal_n), inf = false;

		for (int i = 0, temp_bal = 0; i < length; i++) {
			if (bal_n == 0) {
				if (targ_bal == temp_bal)
					inf = true;
			} else if (abs(targ_bal - temp_bal) % abs(bal_n) == 0)
				if ((targ_bal - temp_bal) / bal_n >= 0)
					ans++;
			s[i] == '0' ? temp_bal++ : temp_bal--;
		}
		std::cout << (inf ? -1 : ans) << "\n";
	}
}

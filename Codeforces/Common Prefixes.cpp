/*
 * Common Prefixes.cpp
 */
#include <iostream>

int main() {
	int n, tc;

	std::cin >> tc;
	while (tc--) {
		std::cin >> n;
		std::string s(200, 'a');

		std::cout << s << '\n';

		for (int i = 0, change; i < n; i++) {
			std::cin >> change;
			s[change] = s[change] == 'a' ? 'b' : 'a';
			std::cout << s << "\n";
		}
	}
}

/*
My original dumbass solution (did not work in the slightest)
I tried to dynamicaly create new strings
but came to a problem when having to create a
string that would be used for a larger length

Read the editorial and am like ok.
I had tried to think of a way to create strings
that would only require the previous strings information
but that would not require all previous ones, so really stupid

int main() {
	int n, tc;
	char a, track;
	std::vector<int> v;

	std::cin >> tc;

	while (tc--) {
		std::cin >> n, v.resize(n);
		std::vector <std::string> prev;
		std::string cur;
		for (int i = 0; i < n; i++)
			std::cin >> v[i];
		a = 'a';
		cur = "";
		for (int i = 0; i < std::max(v[0], 1); i++)
			cur += a++;
		prev.push_back (cur);
		track = 'b';

		for (int i = 0; i < n; i++) {
			cur = "";
			if (v[i] >= v[i + 1]) {
				if (v[i] == 0)
					std::cout << track << "\n";
				else
					prev.push_back (prev[i]);
			} else {
				if (v[i] == 0)
					cur += track;
				else {
					for (int j = 0; i < v[i]; j++)
						cur += prev[i][j];
				}
				a = 'a';
				for (int j = 0; j < v[i + 1] - v[i]; j++)
					cur += a++;
			}
			track++;
		}
	}
}
*/

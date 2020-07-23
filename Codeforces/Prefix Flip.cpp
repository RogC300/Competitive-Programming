/*
 * Prefix Flip.cpp
 */
#include <iostream>
#include <vector>

int main() {
	std::string a, b;
	int n, cur_b, tc;
	bool flip;
	char cur_num;
	std::vector<int> indexes, cmd;

	std::cin >> tc;
	while (tc--) {
		std::cin >> n >> a >> b, flip = false;
		indexes.clear(), cmd.clear();

		for (int i = 0; i < n / 2; i++)
			indexes.push_back(i), indexes.push_back(n - i - 1);
		if (n % 2 != 0)
			indexes.push_back(n / 2);

		cur_b = n - 1;
		for (auto cur_a : indexes) {
			cur_num = a[cur_a];
			if (flip)
				cur_num = (cur_num == '0' ? '1' : '0');

			if (cur_num == b[cur_b])
				cmd.push_back(1);
			cmd.push_back(cur_b + 1);

			flip = !flip, cur_b--;
		}
		std::cout << cmd.size() << " ";
		for (auto i : cmd)
			std::cout << i << " ";
		puts("");
	}
}
/*
 Definatly a more technical problem
 Don't think about the most optimal solution
 Basically this solution just involves shifted digits
 one at a time to the end, the hard part was figuring out
 which would be my first number in order to shift to the
 last position without changing the string itself
 The trial and error below shows that the order of which
 the first position changes based on the original goes
 1, 10, 2, 9, 3, 8 etc

 */

/*
 1 0 0 0 1 1 0 1 0 0
 1, 10, 2, 9
 0 1 1 0 0 1 1 0 1 1
 1 - 10, 1
 1 1 1 0 0 1 1 0 1 1
 0 0 0 1 1 0 0 1 0 0
 0 0 1 0 0 1 1 0 0 0
 1 - 9, 10
 1 0 1 0 0 1 1 0 0  0
 0 1 0 1 1 0 0 1 1  0
 1 1 0 0 1 1 0 1 0  0
 1 - 8, 2
 0 1 0 0 1 1 0 1  0 0
 1 0 1 1 0 0 1 0  0 0
 0 1 0 0 1 1 0 1  0 0
 1 - 7, 9
 */

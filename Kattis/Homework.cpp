/*
 * Homework.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrix;
std::string s, s1, s2;
// y = s1
// x = s2
void findNext(int y, int x) {
	if (matrix[s1.size()][s2.size()] == 1 || x + y == (int)s.size())
		return;

	if (s[y + x] == s1[y] && y <= (int) s1.size() && matrix[y + 1][x] == -1) {
		matrix[y][x] = 1;
		findNext(y + 1, x);
	}

	if (s[y + x] == s2[x] && x <= (int) s2.size() && matrix[y][x + 1] == -1) {
		matrix[y][x] = 1;
		findNext(y, x + 1);
	}
//	if (s[y+x] != s1[y] && s[y+x] != s2[y])
//		matrix[y][x] = 0;
}

int main() {
	std::cin >> s >> s1 >> s2;
	matrix.resize(s1.size() + 1);

	for (int i = 0; i < (int) matrix.size(); i++) {
		matrix[i].resize((int) s2.size() + 1);
		for (int j = 0; j < (int) s2.size() + 1; j++)
			matrix[i][j] = -1;
	}
	matrix[0][0] = 0;
	findNext(0, 0);
	if (matrix[s1.size() - 1][s2.size()] == 1 || matrix[s1.size()][s2.size() - 1] == 1)
		std::cout << "yes\n";
	else {
		std::cout << "no\n";
	}
	// output array
	/*
		for (int i = 0; i < (int)matrix.size(); i++){
	 for (int j = 0; j < (int)matrix[0].size(); j++)
	 std::cout << matrix[i][j] << "\t";
	 std::cout << std::endl;
	 }
*/
}
/*
 babaabbbbbbaababbbbbbabbbbabbbbaaaabbbaaabaabaaababbabaabbba
 baaaabbbaaabaabaaababbabaabbba
 babaabbbbbbaababbbbbbabbbbabbb

 baaaabba
 baaa
 abba
 */

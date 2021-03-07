#include <iostream>
#include <vector>

void out(std::vector<std::vector<char>> a) {
	for (int i = 0; i < (int) a.size(); i++) {
		for (int j = 0; j < (int) a[0].size(); j++)
			std::cout << a[i][j];
		std::cout << "\n";
	}
	std::cout << "\n";
}

void rotate(std::vector<std::vector<char>> &a) {
	std::vector<std::vector<char>> b = a;
	int n = a.size();

	int i = 0, j = 0;
	for (int x = 0; x < n; x++) {
		for (int y = (n - 1); y >= 0; y--)
			b[i][j] = a[y][x], j++;
		i++, j = 0;
	}
	a = b;
}

int check(std::vector<std::vector<char>> big,
		std::vector<std::vector<char>> small) {
	int size = big.size() - small.size() + 1, y, x, count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			y = x = 0;
			bool found = true;
			for (int l = i; l < (int) small.size() + i; l++) {
				for (int k = j; k < (int) small.size() + j; k++) {
					if (small[y][x] != big[l][k])
						found = false;
					x++;
				}
				y++;
				x = 0;
			}
			if (found)
				count++;
		}
	}
	return count;
}

int main() {
	while (true) {
		std::vector<std::vector<char>> big, small;
		int bigInt, smallInt;
		std::cin >> bigInt >> smallInt;
		if (bigInt == 0 || smallInt == 0)
			break;
		big.resize(bigInt);
		small.resize(smallInt);

		for (int i = 0; i < bigInt; i++)
			for (int j = 0; j < bigInt; j++) {
				char in;
				std::cin >> in;
				big[i].push_back(in);
			}

		for (int i = 0; i < smallInt; i++)
			for (int j = 0; j < smallInt; j++) {
				char in;
				std::cin >> in;
				small[i].push_back(in);
			}

		for (int i = 0; i < 4; i++) {
			std::cout << check(big, small);
			if (i != 3)
				std::cout << " ";
			rotate(small);
		}
		std::cout << "\n";
	}
}

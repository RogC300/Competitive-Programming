/*
 * 10161 - Ant on a Chessboard.cpp
 */
#include <iostream>
#include <cmath>

int find_root(int n) {
	double root = sqrt(n);
	if (root == floor(root) && (int) root % 2 == 0)
		return (int) root - 1;
	if (root == floor(root) && (int) root % 2 == 1)
		return (int) root;

	if ((int) floor(root) % 2 == 1)
		return (int) floor(root);
	return (int) ceil(root);

}

std::pair<int, int> find_coord(int root, int n) {
	if (root * root == n)
		return {root, 1};

	if (n < root * root) {
		if (n >= root * root - root + 1)
			return {root, 1 + root * root - n};
		else
			return {root - (root*root - root + 1) + n, root};
	} else {
		if (n <= root * root + root + 1)
			return {root + 1, n - root*root};
		else
			return {root - (n - (root*root + root + 1)) + 1, root + 1};
	}
}

int main() {
	int n, root;
	std::pair<int, int> p;
	while (std::cin >> n && n != 0) {
		root = find_root(n), p = find_coord(root, n);
		printf("%d %d\n", p.second, p.first);
	}
}

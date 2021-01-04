/*
 * 524 - Prime Ring Problem.cpp
 */
#include<cmath>
#include<iostream>

bool used[17] = { false };
int circle[17], n, cases = 0;

bool is_prime(int p) {
	if (p % 2 == 0)
		return false;
	for (int i = 3; i <= sqrt(p) + 1; i += 2)
		if (p % i == 0)
			return false;
	return true;
}

void bfs(int index) {
	if (index == n - 1) {
		if (is_prime(circle[index] + circle[n]))
			for (int i = 0; i < n; i++)
				std::cout << circle[i] << (i == n - 1 ? "\n" : " ");
		return;
	}
	for (int i = 2; i <= n; i++)
		if (!used[i] && is_prime(circle[index] + i)) {
			circle[index + 1] = i;
			used[i] = true;
			bfs(index + 1);
			used[i] = false;
		}
}

int main() {
	while (scanf("%d", &n) == 1) {
		cases++;
		if (cases > 1)
			puts("");
		printf("Case %d:\n", cases);
		circle[0] = circle[n] = 1;
		bfs(0);
	}
}

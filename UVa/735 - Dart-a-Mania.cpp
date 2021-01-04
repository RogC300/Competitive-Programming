/*
 * 735 - Dart-a-Mania.cpp
 */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

std::vector<int> unique;
int u;
void set_up() {
	std::set<int> temp;
	for (int i = 1; i <= 20; i++)
		temp.insert(i), temp.insert(i * 2), temp.insert(i * 3);
	for (auto& it : temp)
		unique.push_back(it);
	unique.push_back(50);
	unique.push_back(0);
	std::sort(unique.begin(), unique.end());
	u = unique.size();
}

void print() {
	for (int i = 0; i < (int) unique.size(); i++)
		std::cout << unique[i] << std::endl;
}

int main() {
	int score;
	set_up();
	while (std::cin >> score && score > 0) {
		int com = 0, perm = 0;
		for (int a = 0; a < u; a++)
			for (int b = a; b < u; b++)
				for (int c = b; c < u; c++)
					if (unique[a] + unique[b] + unique[c] == score)
						com++;
		for (int a = 0; a < u; a++)
			for (int b = 0; b < u; b++)
				for (int c = 0; c < u; c++)
					if (unique[a] + unique[b] + unique[c] == score)
						perm++;
		if (com == 0)
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
		else
			printf(
					"NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\nNUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",
					score, com, score, perm);
		for (int i = 0; i < 70; i++)
			printf("*");
		puts("");
	}
	puts("END OF OUTPUT");
}

/*
 * 978 - Lemmings Battle!.cpp
 *
 *      Author: Roger
 */
#include <iostream>
#include <set>
#include <iterator>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>

int main() {
	int runs;
	std::cin >> runs;
	for (int r = 0; r < runs; r++) {
		if (r > 0)
			puts("");
		int fields, green, blue;
		std::cin >> fields >> green >> blue;
		std::multiset<int, std::greater<int>> gSol, bSol;
		for (int i = 0, sol; i < green; i++) {
			std::cin >> sol;
			gSol.insert(sol);
		}
		for (int i = 0, sol; i < blue; i++) {
			std::cin >> sol;
			bSol.insert(sol);
		}

		while (!gSol.empty() && !bSol.empty()) {
			std::vector<int> gTemp, bTemp;
			fields = std::min((int) std::min(gSol.size(), bSol.size()), fields);
			for (int i = 0; i < fields; i++) {
				std::multiset<int, std::greater<int>>::iterator gitr =
						gSol.begin(), bitr = bSol.begin();
				int g = *gitr, b = *bitr;
				gSol.erase(gitr);
				bSol.erase(bitr);
				if (g > b)
					g -= b, gTemp.push_back(g);
				else if (b > g)
					b -= g, bTemp.push_back(b);
			}

			for (int i = 0; i < (int) gTemp.size(); i++)
				gSol.insert(gTemp[i]);
			for (int i = 0; i < (int) bTemp.size(); i++)
				bSol.insert(bTemp[i]);

//			for (auto i = gSol.begin(); i != gSol.end(); i++)
//				printf("%d\n", *i);
//			puts("");
//			for (auto i = bSol.begin(); i != bSol.end(); i++)
//				printf("%d\n", *i);
//			break;
		}
		if (!gSol.empty()) {
			puts("green wins");
			for (auto i = gSol.begin(); i != gSol.end(); i++)
				printf("%d\n", *i);
		} else if (!bSol.empty()) {
			puts("blue wins");
			for (auto i = bSol.begin(); i != bSol.end(); i++)
				printf("%d\n", *i);
		} else
			printf("green and blue died\n");
	}
}
/*
 1
 1 23 7
 94
 90
 89
 87
 77
 69
 65
 65
 64
 63
 60
 59
 57
 52
 49
 38
 35
 30
 25
 21
 17
 14
 14

 98
 56
 54
 48
 32
 16
 9

 1
 2 2 3
 20
 10

 10
 10
 15

 1
 3 3 3
 10
 20
 30

 30
 100
 30
 */

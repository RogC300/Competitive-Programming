/*
 * House Lawn.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>

std::vector<std::string> mowers;
std::vector<std::vector<int>> info;

void in(int numOfMowers) {
	mowers.resize(numOfMowers);
	info.resize(numOfMowers);
	char input;
	for (int i = 0; i < numOfMowers; i++) {
		mowers[i] = "";
		int count = 0, temp;
		while (scanf("%c", &input)) {
			if (input == ',') {
				count++;
				std::cin >> temp;
				info[i].push_back(temp);
				if (count == 4)
					break;
			} else if (input == '\n')
				continue;
			else
				mowers[i].push_back(input);
		}
	}
/*	for (int i = 0; i < numOfMowers; i++){
		 std::cout << mowers[i] << " ";
		 for (int j = 0; j < 4; j++)
		 std::cout << info[i][j] << " ";
		 std::cout << std::endl;
	 }
*/
}

// 10080ct/(t + r)
// 0 = cost										p
// 1 = cut grass per minute 					c
// 2 = cutting time (how long it can cut for)   t
// 3 = recharge time 							r
// week = 10 080 minutes

int main() {
	int lawnSize, numOfMowers, lowestCost = 100001;
	scanf("%d %d", &lawnSize, &numOfMowers);
	in(numOfMowers);
	std::vector<int> finalists;

	for (int i = 0; i < numOfMowers; i++) {
		long double grassCutPerWeek = (10080.0*info[i][1]*info[i][2]) / (double)(info[i][2]+info[i][3]);
	//	std::cout << mowers[i] << " " << grassCutPerWeek << std::endl;

		if (grassCutPerWeek >= lawnSize) {
			finalists.push_back(i);
			lowestCost = std::min(lowestCost, info[i][0]);
		}
	}
	if (finalists.size() == 0)
		std::cout << "no such mower";
	else
		for (int i = 0; i < (int) finalists.size(); i++)
			if (info[finalists[i]][0] == lowestCost)
				std::cout << mowers[finalists[i]] << std::endl;
}


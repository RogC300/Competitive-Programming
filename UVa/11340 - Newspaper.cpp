/*
 * 11340 - Newspaper.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>

int main() {
	int runs;
	scanf ("%d", &runs);
	while (runs--){
	int numOfPaidCharacters, numOfLines, jj, kk;
	double costTemp, totalWorth = 0;
	char charTemp;
	std::string line;
	std::vector <char> paidChar;
	std::vector <double> charWorth;
	scanf ("%d", &numOfPaidCharacters);

	for (int i = 0; i < numOfPaidCharacters; i++){
		std::cin >> charTemp >> costTemp;
		costTemp /= 100;
		paidChar.push_back(charTemp);
		charWorth.push_back(costTemp);
	}
	scanf ("%d\n", &numOfLines);
	for (int i = 0; i < numOfLines; i++){
		getline (std::cin, line);
		for (unsigned int j = 0; j < line.length(); j++){
			jj = j;
			for (unsigned int k = 0; k < paidChar.size(); k++){
				kk = k;
				if (line[jj] == paidChar[kk]) totalWorth += charWorth[k];
			}
		}
	}
	printf ("%.2f$\n", totalWorth);
	}
}

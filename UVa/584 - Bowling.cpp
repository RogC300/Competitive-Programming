/*
 * 584 - Bowling.cpp
 *
 *      Author: Roger
 */
#include <iostream>
#include <algorithm>
#include <vector>

int toInt(char c) {
	if (isdigit(c))
		return c - '0';
	else
		return 10;
}

void out(std::string s) {
	for (int i = 0; i < (int) s.length(); i++)
		std::cout << s[i] << " ";
	std::cout << std::endl;
}

int main() {
	std::string gameResult;
	while (getline(std::cin, gameResult) && gameResult[0] != 'G') {
		int sum = 0, frame = 0;

		gameResult.erase(
				remove_if(gameResult.begin(), gameResult.end(), isspace),
				gameResult.end());
//		out(gameResult);
//		1 0 1 / 2 2 X 3 3 X 1 / 3 / X 1 2
		for (int i = 0; i < (int) gameResult.length(); i++)
			if (gameResult[i] == 'X' && i < (int) gameResult.length() - 2){
				frame += 2;
				if (frame >= 19){
					sum += 10;
					continue;
				}
				int add = 10 + toInt(gameResult[i + 1]);
				if (gameResult[i+2] == '/')
					add += 10 - toInt(gameResult[i + 1]);
				else
					add += toInt(gameResult[i+2]);
				sum += add;
//				std::cout << add << " ";
//				std::cout << gameResult[i] << "1 ";
			}
			else if (gameResult[i] == '/' && i < (int) gameResult.length()-2){
				frame++;
				sum += 10 - toInt(gameResult[i - 1]) + toInt(gameResult[i + 1]);
//				std::cout << 10 - toInt(gameResult[i - 1]) + toInt(gameResult[i + 1]) << " ";
//				std::cout << gameResult[i] << "2 ";
			}
			else{
				int add;
				frame++;
				if (gameResult[i] == '/' && i >= (int)gameResult.size()-2)
					add = 10 - toInt (gameResult[i-1]);
				else
					add = toInt(gameResult[i]);
				sum += add;
//				std::cout << add << " ";
//				std::cout << gameResult[i] << "3 ";
			}


		printf ("%d\n", sum);
	}
}


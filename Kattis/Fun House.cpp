/*
 * Fun House.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>

void output(std::vector <std::vector <char>> house){
	static int houseNum = 1;
	std::cout << "HOUSE " << houseNum << "\n";
	int height = house.size();
	int width = house[0].size();
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++)
			std::cout << house[i][j];
		std::cout << "\n";
	}
	houseNum++;
}

std::vector <int> solve(std::vector <std::vector <char>> house, int y, int x, int direction){
	int height = house.size();
	int width = house[0].size();
	std::vector <int> answers;
	if (direction == 1)
		for (int i = y-1; i >= 0; i--){
			if (house[i][x] == '/')
				return solve (house, i, x, 4);
			if (house[i][x] == '\\')
				return solve (house, i, x, 3);
			if (house[i][x] == 'x'){
		//		std::cout << "asd";
				answers.push_back(i);
				answers.push_back(x);
				return answers;
			}

		}

	if (direction == 2)
		for (int i = y+1; i < height; i++){
			if (house[i][x] == '/')
				return solve (house, i, x, 3);
			if (house[i][x] == '\\')
				return solve (house, i, x, 4);
			if (house[i][x] == 'x'){
				answers.push_back(i);
				answers.push_back(x);
				return answers;
			}
		}

	if (direction == 3)
		for (int j = x-1; j >= 0; j--){
			if (house[y][j] == '/')
				return solve (house, y, j, 2);
			if (house[y][j] == '\\')
				return solve (house, y, j, 1);
			if (house[y][j] == 'x'){
				answers.push_back(y);
				answers.push_back(j);
				return answers;
			}
		}

	if (direction == 4)
		for (int j = x+1; j <= width; j++){
			if (house[y][j] == '/')
				return solve (house, y, j, 1);
			if (house[y][j] == '\\')
				return solve (house, y, j, 2);
			if (house[y][j] == 'x'){
				answers.push_back(y);
				answers.push_back(j);
				return answers;
			}
		}
	return answers;
}

// 1 = up 2 = down 3 = left 4 = right


int main() {
	while (true){
	std::vector <std::vector <char>> house;
	char temp;
	int width, height;
	std::vector <int> answer;
	std::cin >> width >> height;
	if (width+height == 0) break;
	house.resize(height);
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			std::cin >> temp;
			house[i].push_back(temp);
		}
	}
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (house[i][j] == '*'){
				int direction;
				if (i == height-1) direction = 1;
				if (i == 0) direction = 2;
				if (j == width-1) direction = 3;
				if (j == 0) direction = 4;
				answer = solve(house, i, j, direction);
				break;
			}

	house[answer[0]][answer[1]] = '&';
	output (house);

	}
}




/*
 * What does the fox say.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>

bool usedCheck(std::vector <std::string> a, std::string as){
	int size = a.size();
	for (int i = 0; i < size; i++)
		if (a[i] == as)
			return true;

	return false;
}


int main(){
	int runs;
	std::cin >> runs;
	std::cin.ignore();

	while (runs--){
	std::string line, x = "";
	std::vector <std::string> words, used;
	std::getline(std::cin, line);
	line += ' ';
	int length = line.length();

	for (int i = 0; i < length; i++){
		if (line[i] != ' ') x += line[i];
		if (line[i] == ' '){
	//		if (usedCheck(words, x) == false)
			words.push_back(x);
			x = "";
		}
	}

	while (true){
		std::string temp, currWord = "";
		std::getline(std::cin, temp);
	//	std::cout << temp << std::endl;
		if (temp == "what does the fox say?") break;
		int usedLength = temp.length(), wordCount = 0;
		bool yes = false;
		for (int i = 0; i < usedLength; i++){
			if (temp[i] == ' ') wordCount++;
			if (wordCount == 2) yes = true;
			if (yes == true && temp[i] != ' ') currWord += temp[i];
		}
		if (usedCheck(used, currWord) == false)
			used.push_back(currWord);
	}
	int wordLength = words.size(), usedLength = used.size();
/*
	for (int i = 0; i < wordLength; i++) std::cout << words[i] << " ";
	std::cout << std::endl;
	for (int i = 0; i < usedLength; i++) std::cout << used[i] << " ";
	std::cout << std::endl;
*/
//	if (words[1] == used[0]) std::cout << "Asd";
	for (int i = 0; i < wordLength; i++)
		for (int j = 0; j < usedLength; j++){
			if (words[i] == used[j])
				words[i] = "";
		}

	int asd = words.size();
	for (int i = 0; i < asd; i++){
		if (words[i] != "")
		std::cout << words[i] << " ";
	}

	}

}




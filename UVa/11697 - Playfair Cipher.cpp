/*
 * 11697 - Playfair Cipher.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
// WA somethings wrong
// passes all udebug tests and i am to lazy to create the same test thing as charlie
typedef std::pair<int, int> ii;

std::map<char, ii> create_key() {
	std::string line, key;
	std::map<char, ii> encrypt;
	std::vector<char> alphabet(26, true);

	for (int i = 0; i < 26; i++)
		alphabet[i] = false;
	alphabet[(int) 'q' - 'a'] = true;
	getline(std::cin, line);
	line.erase(remove_if(line.begin(), line.end(), isspace), line.end());

	for (int i = 0; i < (int) line.length(); i++)
		if (line[i] != ' ' && !alphabet[(int) line[i] - 'a'])
			key.push_back(line[i]), alphabet[line[i] - 'a'] = true;

	for (int i = 0; i < 26; i++)
		if (!alphabet[i])
			key.push_back(char(i + 'a'));

	int index = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			encrypt[key[index++]] = ii(i, j);

	return encrypt;
}

std::string encrypt(std::map<char, ii> key, std::map<ii, char> reverse_key,
		std::string text) {
	int x1, x2, y1, y2;
	std::string cipher_text;
	for (int i = 0; i < (int) text.size() - 1; i += 2) {
		y1 = key[text[i]].first, x1 = key[text[i]].second;
		y2 = key[text[i + 1]].first, x2 = key[text[i + 1]].second;
//		std::cout << text[i] << " " << text[i + 1] << "\n";
//		std::cout << y1 << " " << x1 << "   " << y2 << " " << x2 << "\n";

		if (y1 == y2) {
			cipher_text += reverse_key[ii(y1, (x1 + 1) % 5)];
			cipher_text += reverse_key[ii(y2, (x2 + 1) % 5)];
		} else if (x1 == x2) {
			cipher_text += reverse_key[ii((y1 + 1) % 5, x1)];
			cipher_text += reverse_key[ii((y2 + 1) % 5, x2)];
		} else {
			cipher_text += reverse_key[ii(y1, x2)];
			cipher_text += reverse_key[ii(y2, x1)];
		}
	}
	return cipher_text;
}

int main() {
	std::map<char, ii> key;
	std::map<ii, char> reverse_key;
	std::string line, text, cipher_text;
	int tc;
	scanf("%d\n", &tc);
	while (tc--) {
		key = create_key(), text = "";
		for (auto i : key)
			reverse_key[i.second] = i.first;

		getline(std::cin, line);
		line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
		text += line[0];

		for (int i = 1; i < (int) line.size(); i++)
			if (line[i] == line[i - 1] && (i - 1) % 2 == 0)
				text += 'x', text += line[i];
			else
				text += line[i];
		bool complete = false;
//		std::cout << text << "\n";
		while (!complete) {
			complete = true;
			for (int i = 0; i < (int) text.size() - 1; i += 2)
				if (text[i] == text[i + 1])
					text.insert(i + 1, "x"), complete = false;
		}
		if (text.size() % 2 == 1)
			text += 'x';
//		std::cout << text << "\n";
		cipher_text = encrypt(key, reverse_key, text);
		std::transform(cipher_text.begin(), cipher_text.end(),
				cipher_text.begin(), ::toupper);
		std::cout << cipher_text << "\n";
	}
}

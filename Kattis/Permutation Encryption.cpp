/*
 * Problem A Permutation Encryption.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>
#include <string>

int main() {
	while (true){

	int keyLength;
	std::vector <int> key;
	std::string plain, cipher;

	std::cin >> keyLength;
	if (keyLength == 0) break;
	key.resize(keyLength);
	for (int i = 0; i < keyLength; i++){
		std::cin >> key[i];
		key[i] -= 1;
	}
    std::cin.ignore();

	std::getline (std::cin, plain);
	int count = 0, length = plain.length();

	if (length % keyLength != 0){
		int j = length % keyLength;
		int pad = keyLength - j;
		for (int i = 0; i < pad; i++) plain += " ";
	}
	length = plain.length();

	cipher = plain;
	bool last = false;
	while (true){
		for (int i = 0+count, keyCount = 0; i < keyLength+count; i++){
			if (i > length){
				last = true;
				break;
			}
			cipher[i] = plain[key[keyCount]+count];
			keyCount++;
		}
		count += keyLength;
		if (last == true) break;
		if (count > length) break;
	}

	std::cout << "'" << cipher << "'\n";

	}
}


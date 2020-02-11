/*
 * Baby Bites.cpp
 *
 *      Author: tempo
 */
#include <iostream>

int main() {
	int n; scanf ("%d", &n);
	bool solved = true;
	for (int i = 1; i <= n; i++){
		std::cin >> std::ws;
		char num = std::cin.peek();
		if (num == 'm'){
	//		std::cout << "asd";
			std::string aas;
			std::cin >> aas;
			continue;
		}
		int a;
		std::cin >> a;
	//	std::cout << a << std::endl;
		if (a != i){
			solved = false;
		}
	}

	if (solved == false) std::cout << "something is fishy";
	else std::cout << "makes sense";


}


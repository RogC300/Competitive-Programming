/*
 * 787 - Maximum Sub-sequence Product.cpp
 */
#include <iostream>

#include "../Proble/Big Int.h"

int main() {
	int numbers[200];
	while (std::cin >> numbers[0]) {
		int size = 1;
		bigint max_product(numbers[0]);
		int input;
		while (std::cin >> input && input != -999999)
			numbers[size++] = input, max_product *= input;

		for (int i = 0; i < size; i++) {
			bigint temp_product(1);
			for (int k = i; k < size; k++) {
				temp_product *= numbers[k];
				if (temp_product > max_product)
					max_product = temp_product;
			}
		}
		std::cout << max_product << std::endl;
	}
}

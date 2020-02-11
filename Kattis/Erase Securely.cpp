/*
 * Erase Securely.cpp
 */
#include <iostream>

int main() {
	int swaps;
	std::string a, b;
	std::cin >> swaps >> a >> b;
	if (swaps % 2 == 0) {
		if (a != b)
			printf("Deletion failed");
		else
			printf("Deletion succeeded");
	} else {
		for (int i = 0; i < (int) a.length(); i++)
			if (a[i] == '0')
				a[i] = '1';
			else
				a[i] = '0';
		if (a != b)
			printf("Deletion failed");
		else
			printf("Deletion succeeded");
	}
}

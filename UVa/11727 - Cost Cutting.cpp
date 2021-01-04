/*
 * 11727.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	int runs, temp, counter = 1;
	scanf ("%i", &runs);

	for (int i = 0; i < runs; i++){
		std::vector <int> salaries;
		for (int i = 0; i < 3; i++){
		scanf("%i", &temp);
		salaries.push_back(temp);
		}
		std::sort (salaries.begin(), salaries.end());
		printf("Case %i: %i\n", counter, salaries[1]);
		counter++;
	}
}

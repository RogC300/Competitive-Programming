/*
 * 10038 - Jolly Jumpers.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
	int n;
	while (scanf ("%d", &n) == 1){
	int input, dif;
	std::vector <int> vec, difference;
	bool status = true;
	for (int i = 0; i < n; i++){
		scanf ("%d", &input);
		vec.push_back (input);
	}
	for (unsigned int i = 0; i < vec.size()-1; i++){
		dif = abs(vec[i]-vec[i+1]);
		difference.push_back(dif);
	}
	std::sort (difference.begin(), difference.end());

	for (unsigned int i = 1; i <= difference.size(); i++){
		int j = i;
		if (difference[i-1] != j){
			status = false;
			break;
		}
	}
	if (status) printf ("Jolly\n");
	else printf ("Not jolly\n");
	}
}


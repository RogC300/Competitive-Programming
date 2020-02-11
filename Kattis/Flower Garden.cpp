/*
 * Flower Garden.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

long double distance(int curX, int curY, int nextX, int nextY){
	int dX = abs(curX-nextX);
	int dY = abs(curY-nextY);
	return sqrt(dX*dX+dY*dY);
}

int wateredPlants (int numOfFlowers, std::vector <std::pair <int, int>> flowers, long double maxDistance){
	int curX = 0, curY = 0;
	long double distanceTraveled = 0;
	for (int i = 0; i < numOfFlowers; i++){
		long double travel = distance(curX, curY, flowers[i].first, flowers[i].second);
		if (distanceTraveled + travel <= maxDistance){
			distanceTraveled += travel;
			curX = flowers[i].first;
			curY = flowers[i].second;
		}
		else
			return i;
	}
	return numOfFlowers;
}

bool isPrime(int n){
	if (n == 2 || n == 3) return true;
	if (n % 2 == 0) return false;
	if (n == 1 || n == 0) return false;
	for (int i = 3; i <= sqrt(n); i += 2)
		if (n % i == 0)
			return false;

	return true;
}


int main() {
	long double runs;
	std::cin >> runs;
	while (runs--){
		int numOfFlowers;
		long double maxDistance;
		std::vector <std::pair <int, int>> flowers;
		std::cin >> numOfFlowers >> maxDistance;
		flowers.resize(numOfFlowers);
		for (int i = 0, x, y; i < numOfFlowers; i++){
			std::cin >> x >> y;
			flowers[i].first = x;
			flowers[i].second = y;
		}
		int index = wateredPlants(numOfFlowers, flowers, maxDistance);

		for (int i = index; i >= 0; i--){
			if (isPrime(i)){
				index = i;
				break;
			}
			if (i == 0)
				index = 0;
		}
		std::cout << index << std::endl;
	}
}

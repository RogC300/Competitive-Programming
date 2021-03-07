/*
 * 11498.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <string>

int main(){
	std::string line;
	int runs = 1, originX, originY;
	int coordX, coordY;
	while (true){
	scanf("%i", &runs);
	if (runs == 0)
		break;
	scanf("%i %i", &originX, &originY);

	for (int i = 0; i < runs; i++){
		scanf("%i %i", &coordX, &coordY);

		if (originX == coordX || originY == coordY)
			printf("divisa\n");
		else if (coordX > originX && coordY > originY)
			printf("NE\n");
		else if (coordX < originX && coordY > originY)
			printf("NO\n");
		else if (coordX > originX && coordY < originY)
			printf("SE\n");
		else
			printf("SO\n");
	}
}
}


/*
 * Anthony and Diablo.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <cmath>

int main() {
	double size, fence;
	scanf ("%lf %lf", &size, &fence);

	if (size <= (fence*fence)/(4*3.1415))
		printf ("Diablo is happy!");
	else
		printf ("Need more materials!");
}


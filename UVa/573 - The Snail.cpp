/*
 * 573.cpp
 *
 *      Author: tempo
 */
#include <iostream>

int main(){
	double wellHeight = -1, climbDistance, downDistance, fatiguePercent;

	while (true){
		scanf ("%lf %lf %lf %lf", &wellHeight, &climbDistance, &downDistance, &fatiguePercent);
		if (wellHeight == 0)
			break;
		int finalDay = 1, day = 1;
		double currentHeight = 0, fatigue = climbDistance*(fatiguePercent/100);
		bool success = false;
		while (true){
			if (wellHeight == climbDistance){
				currentHeight += climbDistance;
				if (currentHeight-downDistance < 0) {
					finalDay = day;
					break;
				}
				else currentHeight -= downDistance;
				climbDistance -= fatigue;
				if (climbDistance < 0)
					climbDistance = 0;
				day++;
			}

			currentHeight += climbDistance;
			if (currentHeight >= wellHeight){
				finalDay = day;
				success = true;
				break;
			}
			if (currentHeight-downDistance < 0) {
				finalDay = day;
				break;
			}
			else currentHeight -= downDistance;

			climbDistance -= fatigue;
			if (climbDistance < 0)
				climbDistance = 0;

			day++;
		}
		if (success) printf ("success on day %d\n", finalDay);
		else printf ("failure on day %d\n", finalDay);

	}




}




/*
 * 10141.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int main() {
	int counter = 0;
	bool first = true;
	while (true) {
	counter++;
	double numReq, numProp, metReq, compliance = 0, price, bestCost = 1E30;
	std::string name, answer, temp;
	scanf ("%lf %lf\n", &numReq, &numProp);
	if (numReq == 0 || numProp == 0){ break; }

	for (int i = 0; i < numReq; i++) getline (std::cin, temp);

	for (int i = 0; i < numProp; i++){
		getline (std::cin, name);
		scanf ("%lf %lf\n", &price, &metReq);
		for (int i = 0; i < metReq; i++) getline (std::cin, temp);

		if (metReq/numReq > compliance || (metReq/numReq >= compliance && price < bestCost)){
			bestCost = price;
			compliance = metReq/numReq;
			answer = name;
		}
	}
	if (first == false)
		std::cout << "\n";
	else
		first = false;
	std::cout << "RFP #" << counter << std::endl
			<< answer << std::endl;
	}
}




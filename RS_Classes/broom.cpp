#include "broom.h"

Broom::Broom() {
	name = "Метла";
	velocoty = 20;
}

void Broom::raceTimeCalculation(int distance) {
	distanceReductionFactor = distance / 1000; // деление целочисленное
	raceTime = (distance * (1 - distanceReductionFactor/100.0)) / velocoty;
}
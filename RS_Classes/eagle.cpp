#include "eagle.h"

Eagle::Eagle() {
	name = "���";
	velocoty = 8;
}

void Eagle::raceTimeCalculation(int distance) {
	distanceReductionFactor = 6;
	raceTime = (distance * (1 - distanceReductionFactor / 100.0)) / velocoty;
}
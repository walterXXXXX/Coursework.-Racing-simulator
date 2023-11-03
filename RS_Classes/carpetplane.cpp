#include "carpetplane.h"

CarpetPlane::CarpetPlane() {
	name = "Ковёр-самолёт";
	velocoty = 10;
}

void CarpetPlane::raceTimeCalculation(int distance) {
	distanceReductionFactor = 5;
	if (distance < 10000) distanceReductionFactor = 10;
	if (distance < 5000) distanceReductionFactor = 3;
	if (distance < 1000) distanceReductionFactor = 0;
	raceTime = (distance * (1 - distanceReductionFactor / 100.0)) / velocoty;
}
#include "broom.h"

Broom::Broom() {
	name = "�����";
	velocoty = 20;
}

void Broom::raceTimeCalculation(int distance) {
	distanceReductionFactor = distance / 1000; // ������� �������������
	raceTime = (distance * (1 - distanceReductionFactor/100.0)) / velocoty;
}
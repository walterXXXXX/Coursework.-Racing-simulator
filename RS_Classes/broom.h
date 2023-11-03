#pragma once

#include "airvehicle.h"

class Broom : public AirVehicle {
public:
	Broom();

	void raceTimeCalculation(int distance) override; // расчет времени прохождения дистанции ТС типа "метла"
};
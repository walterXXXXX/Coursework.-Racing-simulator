#pragma once

#include "airvehicle.h"

class CarpetPlane : public AirVehicle {
public:
	CarpetPlane();

	void raceTimeCalculation(int distance) override; // расчет времени прохождения дистанции ТС типа "ковер-самолет"
};
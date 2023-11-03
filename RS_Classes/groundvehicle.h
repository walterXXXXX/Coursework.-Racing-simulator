#pragma once

#include "vehicle.h"

// родительский класс для наземных ТС

class GroundVehicle : public Vehicle {
public:
	GroundVehicle();

	void raceTimeCalculation(int distance) override; // расчета времени прохождения дистанции наземным ТС, общая реализация для всех наземных ТС

protected:
	double firstRestTime; // длительность отдыха первый раз
	double secondRestTime; // длительность отдыха второй раз
	double otherRestTime; // длительность отдыха все последующие разы
	double beforeRestTime; // время движения до отдыха
};
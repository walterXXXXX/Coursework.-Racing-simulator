#pragma once

#include "vehicle.h"

// родительский класс для воздушных ТС

class AirVehicle : public Vehicle {
public:
	AirVehicle();

	// т.к. реализация метода расчета прохождения дистанции будет отличаться для разных ТС,
	// перегрузим его непосредственно в классах-потомках для конкретных ТС
	// void raceTimeCalculation(int distance) override;
	
protected:
	int distanceReductionFactor; // коэффициент сокращения дистанции, в %

};
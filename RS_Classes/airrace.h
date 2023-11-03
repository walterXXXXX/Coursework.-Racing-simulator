#pragma once

#include "anyrace.h"

class AirRace : public AnyRace {
public:
	AirRace();

	void registerVehicle(Vehicle* vehicle) override; // метод регистрации на гонку воздушных ТС

};
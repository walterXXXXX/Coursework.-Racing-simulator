#pragma once

#include "anyrace.h"

class GroundRace : public AnyRace {
public:
	GroundRace();

	void registerVehicle(Vehicle* vehicle) override; // метод регистрации на гонку наземных ТС

};
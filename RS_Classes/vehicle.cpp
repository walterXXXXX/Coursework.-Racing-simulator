#include "vehicle.h"

#include <iostream>

Vehicle::Vehicle() {
	velocoty = 0;
	name = "Не определено";
	type = VehicleTypes::UNKNOWN_VEHICLE;
	raceTime = 0;
}

std::string Vehicle::getName() { return name; }

VehicleTypes Vehicle::getType() { return type; }

double Vehicle::getRaceTime() { return raceTime; }

void Vehicle::raceTimeCalculation(int distance) { }
